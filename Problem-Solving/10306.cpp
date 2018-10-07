#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
vector<ii> vcoins;

int m; double s;
long long dP[50][300][300];

long long nCoins(int pos, long long ecoin, long long tcoin) {
    long long res=INF;
    if(ecoin>s || tcoin>s) return INF;
    if(pos==m) {
        if(sqrt(ecoin*ecoin+tcoin*tcoin)==s) return 0;
        return INF;
    }

    if(dP[pos][ecoin][tcoin]!=-1)
        return dP[pos][ecoin][tcoin];

    res = min(min(1+nCoins(pos, ecoin+vcoins[pos].first, tcoin+vcoins[pos].second),
                nCoins(pos+1, ecoin, tcoin)), res);

    dP[pos][ecoin][tcoin] = res;
    return res;
}

int main() {
    int n,x,y;

    cin>>n;
    while(n--) {
        cin>>m>>s;
        vcoins.clear();

        for(int i=0; i<=m; i++)
            for(int j=0; j<301; j++)
                memset(dP[i][j], -1, 301*sizeof(long long));

        for(int i=0; i<m; i++) {
            cin>>y>>x;
            vcoins.push_back(ii(x,y));
        }

        long long res=nCoins(0,0,0);
        if(res==INF) cout<<"not possible"<<endl;
        else cout<<res<<endl;
    }
}
