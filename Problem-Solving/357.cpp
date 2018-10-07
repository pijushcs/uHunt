#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

vector<int> vcent = {1,5,10,25,50};
long long dP[5][30001];

long long nchange(int pos, int n) {
    long long res=0;
    if(n==0) return 1;
    if(n<0 || pos==vcent.size()) return 0;

    if(dP[pos][n]!=-1) return dP[pos][n];

    for(int i=pos; i<vcent.size(); i++)
        res+=nchange(i, n-vcent[i]);

    dP[pos][n] = res;
    return res;
}

int main() {
    int n;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    for(int i=0; i<5; i++)
        memset(dP[i], -1, (30001)*sizeof(long long));

    nchange(0, 30000);

    while(scanf("%d", &n)!=EOF) {
        long long res=nchange(0, n);

        if(res>1)
            printf("There are %lld ways to produce %d cents change.\n", res, n);
        else
            printf("There is only 1 way to produce %d cents change.\n", n);;
    }
}
