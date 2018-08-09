#include<iostream>
#include<queue>
using namespace std;

priority_queue<long long> qG, qB;
void comPuteWinner(long long cntB) {
    vector<long long> batG, batB;

    while(!qG.empty() && !qB.empty()) {
        for(int i=0; i<cntB; i++) {
            if(!qG.empty()) {
                batG.push_back(qG.top());
                qG.pop();
            }
            else if(qG.empty()) batG.push_back(0);

            if(!qB.empty()) {
                batB.push_back(qB.top());
                qB.pop();
            }
            else if(qB.empty()) batB.push_back(0);
        }

        for(int i=0; i<cntB; i++) {
            if(batG[i]>batB[i]) qG.push(batG[i]-batB[i]);
            else if(batB[i]>batG[i]) qB.push(batB[i]-batG[i]);
        }

        batB.clear(); batG.clear();
    }

    if(qB.size() > qG.size()) cout<<"blue wins"<<endl;
    else if(qB.size() < qG.size()) cout<<"green wins"<<endl;
    else cout<<"green and blue died"<<endl;

    while(!qB.empty()) {cout<<qB.top()<<endl; qB.pop();}
    while(!qG.empty()) {cout<<qG.top()<<endl; qG.pop();}
}

int main() {
    long long sG, sB, cntB, x;
    int t;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>cntB>>sG>>sB;
        for(int i=0; i<sG; i++) {
            cin>>x; qG.push(x);
        }
        for(int i=0; i<sB; i++) {
            cin>>x; qB.push(x);
        }
        comPuteWinner(cntB);
        if(t!=0) cout<<endl;
    }
}
