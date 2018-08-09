#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int s,b,l,r;
    int sLeft[100010], sRight[100010];

    //freopen("testCase.txt", "r", stdin);
    //freopen("testOut.txt", "w", stdout);

    while(1) {
        cin>>s>>b;
        if(s==0 && b==0) break;

        memset(sLeft, 0, 100010*sizeof(int));
        memset(sRight, 0, 100010*sizeof(int));

        sLeft[1]=-1;
        sRight[s]=-1;

        for(int i=0; i<b; i++) {
            cin>>l>>r;

            if(sRight[r]==0) {
                if(sLeft[l]!=0) sLeft[r+1]=sLeft[l];
                else sLeft[r+1]=l-1;
            }
            else if(sRight[r]!=-1) {
                if(sLeft[l]!=0) sLeft[sRight[r]]=sLeft[l];
                else sLeft[sRight[r]]=l-1;
            }

            if(sLeft[l]==0) {
                if(sRight[r]!=0) sRight[l-1]=sRight[r];
                else sRight[l-1]=r+1;
            }
            if(sLeft[l]!=-1) {
                if(sRight[r]!=0) sRight[sLeft[l]]=sRight[r];
                else sRight[sLeft[l]]=r+1;
            }

            if(sLeft[l]==0) cout<<l-1<<" ";
            else if(sLeft[l]==-1) cout<<"*"<<" ";
            else cout<<sLeft[l]<<" ";

            if(sRight[r]==0) cout<<r+1<<endl;
            else if(sRight[r]==-1) cout<<"*"<<endl;
            else cout<<sRight[r]<<endl;
        }
        cout<<"-"<<endl;
    }
}
