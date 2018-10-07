#include<iostream>
#include<cstring>
using namespace std;

#define XMOD 1000000

long long dP[101][101];

long long nSum(int n, int m) {
    long long res = 0;
    if(n<0) return 0;
    if(m==0 && n==0) return 1;
    if(m==0) return 0;

    if(dP[n][m]!=-1) return dP[n][m];

    for(int i=0; i<=n; i++)
        res=(res+nSum(n-i, m-1))%XMOD;

    dP[n][m] = res;
    return res;
}

int main() {
    int n, m;

    for(int i=0; i<101; i++)
        memset(dP[i], -1, 101*sizeof(long long));

    nSum(100, 100);

    cin>>n>>m;
    while(n!=0 && m!=0) {
        cout<<nSum(n, m)<<endl;
        cin>>n>>m;
    }
}
