#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;

int dP[101][10001], cdP[101][10001], vcoin[101], m;

ii minChange(int pos, int n) {
    if(n<=0) return ii(0,0);
    if(pos==m) return ii(INF, INF);

    if(dP[pos][n]!=-1)
        return ii(dP[pos][n], cdP[pos][n]);

    ii ctake = minChange(pos+1, n-vcoin[pos]);
    ctake.first+=vcoin[pos]; ctake.second+=1;

    ii ntake = minChange(pos+1, n);

    ii res = min(ctake, ntake);

    dP[pos][n]=res.first;
    cdP[pos][n]=res.second;

    return res;
}

int main() {
    int t,n;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n>>m;

        for(int i=0; i<m; i++)
            cin>>vcoin[i];

        for(int i=0; i<m; i++)
            memset(dP[i], -1, 10001*sizeof(0));

        ii res = minChange(0, n);
        cout<<res.first<<" "<<res.second<<endl;
    }
}
