#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long blockSum[110][110]={0};
vector<long long> mRes;

long long sumMax(int r, int c, int n, int m, long long k) {
    long long maxNow=0;
    long long carea;

    for(int i=r; i<=n; i++) {
        for(int j=c; j<=m; j++) {
            long long res = blockSum[i][j]-(blockSum[i][c-1]+blockSum[r-1][j])+blockSum[r-1][c-1];
            carea=(i-r+1)*(j-c+1);

            if(res<=k && mRes[carea]>res) {
                mRes[carea]=res;
                maxNow=max(maxNow, carea);
            }
        }
    }

    return maxNow;
}

int main() {
    int t,n,m, tcase=1;
    long long k, val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n>>m>>k;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                cin>>val; blockSum[i][j]=val+blockSum[i][j-1]+blockSum[i-1][j]-blockSum[i-1][j-1];
            }

        long long marea=0;
        mRes.assign(n*m+10, k+10);
        mRes[0]=0;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                marea=max(marea, sumMax(i,j,n,m,k));

        cout<<"Case #"<<tcase++<<": "<<marea<<" "<<mRes[marea]<<endl;
    }
}
