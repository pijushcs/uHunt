#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n,m,val,tcase=1;

    cin>>n>>m;
    while(n!=0 && m!=0) {
        int mbr=100;
        for(int i=0; i<n; i++) {
            cin>>val;
            mbr=min(mbr, val);
        }

        for(int i=0; i<m; i++) cin>>val;

        cout<<"Case "<<tcase++<<": ";
        if(n==m || n<m) cout<<0<<endl;
        else cout<<(n-m)<<" "<<mbr<<endl;

        cin>>n>>m;
    }
}
