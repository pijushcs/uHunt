#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define INF 10000000000

long long dP[10][1001], vwind[10][1001];
long long ufuel=60, sfuel=30, dfuel=20,d;

long long fuelSpend(int curd, int curh) {
    if(curd==d && curh==0) return 0;
    if(curd>=d || curh<0 || curh>9) return INF;

    if(dP[curh][curd]!=-1)
        return dP[curh][curd];

    long long res = min(min(ufuel-vwind[curh][curd]+fuelSpend(curd+1, curh+1),
                            sfuel-vwind[curh][curd]+fuelSpend(curd+1, curh)),dfuel-vwind[curh][curd]+fuelSpend(curd+1, curh-1));

    dP[curh][curd]=res;
    return res;
}

int main() {
    int t;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>d; d/=100;
        for(int i=9; i>=0; i--) {
            memset(dP[i], -1, (d+1)*sizeof(long long));
            for(int j=0; j<d; j++) cin>>vwind[i][j];
        }

        cout<<fuelSpend(0,0)<<endl<<endl;
    }
}
