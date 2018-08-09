#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

vector<queue<int> > stnVec;

long long timeTaken(int n, int s, int q, int tParcels) {
    int cParcels=0, curStn;
    long long nStn=0;
    long long curTime=0;

    stack<int> rStack;

    while(cParcels<tParcels) {
        if(nStn) curTime+=2;
        curStn=nStn%n+1;

        while(!rStack.empty()) && rStack.top()==curStn || !rStack.empty() && stnVec[curStn].size()<q) {
            if(rStack.top()==curStn) {
                cParcels++;
                rStack.pop();
                curTime++;
            }
            else {
                stnVec[curStn].push(rStack.top());
                rStack.pop();
                curTime++;
            }
        }

        while(rStack.size()<s && !stnVec[curStn].empty()) {
            rStack.push(stnVec[curStn].front());
            stnVec[curStn].pop();
            curTime++;
        }

        nStn++;
    }

    return curTime;
}

int main() {
    int t,n,s,q,sQ,nParcel,tParcel=0;

    freopen("testCase.txt", "r", stdin);
    cin>>t;
    while(t--) {
        cin>>n>>s>>q;
        tParcel=0;
        stnVec.assign(n+1, queue<int>());
        for(int i=1; i<=n; i++) {
            cin>>sQ;
            tParcel+=sQ;
            while(sQ--) {
                cin>>nParcel;
                stnVec[i].push(nParcel);
            }
        }
        cout<<timeTaken(n,s,q,tParcel)<<endl;
    }
}
