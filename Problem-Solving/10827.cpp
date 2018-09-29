#include<iostream>
#include<algorithm>
using namespace std;

int n;

long long blockSum[100][100] = {0};

long long calSumBlock(int pr, int pc, int qr, int qc) {
    return blockSum[qr][qc]-(blockSum[pr-1][qc]+blockSum[qr][pc-1])+blockSum[pr-1][pc-1];
}

long long maxSum(int r, int c) {
    long long maxNow=-1000000000000, res;
    int i=r,j=c;

    while(true) {
        while(true) {
            if(i>=r && j>=c)
                res=calSumBlock(r,c,i,j);
            if(i>=r && j<c)
                res=calSumBlock(r,c,i,n)
                    + calSumBlock(r,1,i,j);
            if(i<r && j>=c)
                res=calSumBlock(r,c,n,j)
                    + calSumBlock(1,c,i,j);
            if(i<r && j<c)
                res=calSumBlock(r,c,n,n)
                    + calSumBlock(1,c,i,n)
                    + calSumBlock(1,1,i,j)
                    + calSumBlock(r,1,n,j);

            maxNow=max(maxNow, res);
            j=j%n+1;
            if(j==c) break;
        }
        i=i%n+1;
        if(i==r) break;
    }

    return maxNow;
}

int main() {
    int t;
    long long val;

    cin>>t;
    while(t--) {
        cin>>n;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) {
                cin>>val;
                blockSum[i][j]=val+blockSum[i-1][j]+blockSum[i][j-1]-blockSum[i-1][j-1];
            }

        long long maxNow=-10000000000000;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                maxNow=max(maxNow, maxSum(i,j));

        cout<<maxNow<<endl;
    }
}
