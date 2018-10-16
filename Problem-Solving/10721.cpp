#include<iostream>
#include<cstring>
using namespace std;

long long dP[51][51];
int n,k,m;

long long barCodes(int curn, int curk) {
    if(curn==0 && curk==0) return 1;
    if(curn<=0 || curk<=0) return 0;

    long long snow=0;
    if(dP[curn][curk]!=-1)
        return dP[curn][curk];

    for(int i=1; i<=m; i++) {
        snow+=barCodes(curn-i,curk-1);
    }

    dP[curn][curk]=snow;
    return snow;
}

int main() {

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>n)) {
        cin>>k>>m;

        for(int i=0; i<=n; i++)
            memset(dP[i], -1, (k+1)*sizeof(long long));

        cout<<barCodes(n,k)<<endl;
    }
}
