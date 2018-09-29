#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long blockSum[110][110] = {0};

long long maxBlock(int r, int c, int n) {
    long long maxNow=-1000000000000, csum=0;

    for(int i=r; i<=n; i++) {
        for(int j=c; j<=n; j++) {
            csum=blockSum[i][j]-(blockSum[i][c-1]+blockSum[r-1][j])+blockSum[r-1][c-1];
            maxNow=max(maxNow, csum);
        }
    }

    return maxNow;
}

int main() {
    int n;
    long long val, maxNow;

    while((cin>>n)) {
        maxNow=-1000000000000;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cin>>val;
                blockSum[i][j]=val+blockSum[i][j-1]+blockSum[i-1][j]-blockSum[i-1][j-1];
            }
        }

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                maxNow=max(maxNow, maxBlock(i,j, n));

        cout<<maxNow<<endl;
    }
}
