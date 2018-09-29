#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long blockSum[30][30][30]={0};
int a, b, c;

void inputRect(int p, int r, int c, long long val) {
    blockSum[p][r][c] = val+blockSum[p][r][c-1]+blockSum[p-1][r][c]-blockSum[p-1][r][c-1];
    blockSum[p][r][c] = blockSum[p][r][c]+blockSum[p][r-1][c]-(blockSum[p-1][r-1][c]+blockSum[p][r-1][c-1]);
    blockSum[p][r][c] += blockSum[p-1][r-1][c-1];
}

long long sumRect(int px, int rx, int cx, int py, int ry, int cy) {
    long long srect=blockSum[py][ry][cy];

    srect=srect - (blockSum[py][ry][cx-1] + blockSum[px-1][ry][cy]) + blockSum[px-1][ry][cx-1]; // got added twice
    srect=srect - blockSum[py][rx-1][cy] + (blockSum[px-1][rx-1][cy] + blockSum[py][rx-1][cx-1]);
    srect=srect - blockSum[px-1][rx-1][cx-1]; // got added twice

    return srect;
}

long long maxSubHeap(int p, int q, int r) {
    long long maxNow=-100000000000;
    for(int i=p; i<=a; i++)
        for(int j=q; j<=b; j++)
            for(int k=r; k<=c; k++)
                maxNow=max(maxNow, sumRect(p,q,r, i,j,k));

    return maxNow;
}

long long maxHeap() {
    long long maxNow=-100000000000;
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            for(int k=1; k<=c; k++)
                maxNow=max(maxNow, maxSubHeap(i,j,k));

    return maxNow;
}

int main() {
    int n;
    long long val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n;
    while(n--) {
        cin>>a>>b>>c;

        for(int i=1; i<=a; i++)
            for(int j=1; j<=b; j++)
                for(int k=1; k<=c; k++) {
                    cin>>val; inputRect(i,j,k,val);
                }

        cout<<maxHeap()<<endl;
        if(n>0) cout<<endl;
    }
}
