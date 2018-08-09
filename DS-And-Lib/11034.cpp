#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

queue<long long> qLeft, qRight;

int findTimeCrossed(long long l, int m) {
    int curPos=0, carCount=0, nCrossed=0;
    long long sumD=0;
    l=l*100;

    while(carCount<m) {
        sumD=0;
        if(!curPos) {
            while(sumD+qLeft.front()<l && !qLeft.empty()) {
                sumD+=qLeft.front();
                carCount++;
                qLeft.pop();
            }
            curPos=1;
        }
        else {
            while(sumD+qRight.front()<l && !qRight.empty()) {
                sumD+=qRight.front();
                carCount++;
                qRight.pop();
            }
            curPos=0;
        }

        nCrossed++;
    }

    return nCrossed;
}

int main() {
    long long l,d;
    int m,t;
    string str;

    freopen("testCase.txt","r",stdin);
    freopen("testOut.txt","w",stdout);
    cin>>t;
    while(t--) {
        cin>>l>>m;

        for(int i=0; i<m; i++) {
            cin>>d>>str;
            if(!str.compare("left"))
                qLeft.push(d);
            else
                qRight.push(d);
        }

        cout<<findTimeCrossed(l,m)<<endl;
    }
}
