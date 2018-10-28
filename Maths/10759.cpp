#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

long long dP[30][200];

long long nWays(int n, int csum, int x) {
    if(n==0 && csum>=x) return 1;
    if(n==0) return 0;

    if(dP[n][csum]!=-1) return dP[n][csum];

    long long res=0;
    for(int i=1; i<=6; i++)
        res+=nWays(n-1, csum+i, x);

    dP[n][csum]=res;
    return res;
}

int gcd(long long a, long long b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    int n,x;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n>>x;
    while(n!=0 || x!=0) {
        for(int i=0; i<=n; i++)
            memset(dP[i], -1, (200)*sizeof(long long));

        long long res=nWays(n,0,x);

        long long nres=1;
        for(int i=1; i<=n; i++) nres*=6;

        if(res==0) cout<<res<<endl;
        else if(nres==res) cout<<1<<endl;
        else {
            long long cgcd=gcd(res,nres);

            while(cgcd!=1) {
                res=res/cgcd; nres=nres/cgcd;
                cgcd=gcd(res,nres);
            }
            cout<<res<<"/"<<nres<<endl;
        }
        cin>>n>>x;
    }
}
