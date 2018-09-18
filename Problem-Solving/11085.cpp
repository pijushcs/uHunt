#include<iostream>
#include<vector>
using namespace std;

vector<int> vcol, actCol;

long long findMoves(int p) {
    long long minNow=10000;

    if(p>8) return 0;

    for(int i=1; i<=8; i++) {
        bool isPossible=true;
        for(int j=1; j<p; j++)
            if(vcol[j]==i || abs(vcol[j]-i)==abs(p-j)) {
                isPossible=false;
                break;
            }

        if(isPossible) {
            vcol[p]=i;
            if(i!=actCol[p]) minNow=min(minNow, 1+findMoves(p+1));
            else minNow=min(minNow, findMoves(p+1));
        }
    }

    return minNow;
}

int main() {
    int val, tcase=1;

    while((cin>>val)) {
        actCol.assign(10, 0);
        vcol.assign(10, 0);

        actCol[1]=val;
        for(int i=2; i<=8; i++) {
            cin>>val; actCol[i]=val;
        }

        cout<<"Case "<<tcase++<<": "<<findMoves(1)<<endl;
    }
}
