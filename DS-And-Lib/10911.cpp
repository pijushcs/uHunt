#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<ii> dist;
double dP[1<<16+1];

int sbit, n=1;

void init(int N) {
    sbit = 0;
    memset(dP, 0, (1<<16+1)*sizeof(double));
    dist.assign(2*N+1, ii(0,0));
}

double valDist(ii a, ii b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

double findMinDist(vii &dist, int s) {
    if(s==2*n) return 0.0;
    if(dP[sbit] != 0.0) return dP[sbit];
    if(sbit&(1<<s)) return findMinDist(dist, s+1);

    sbit = sbit | (1<<s);
    double minNow = 10000000.0;

    for(int i=s+1; i<2*n; i++) {
        if(sbit&(1<<i)) continue;

        sbit = sbit |(1<<i);
        minNow = min(minNow, findMinDist(dist, s+1)+valDist(dist[s],dist[i]));
        sbit = sbit&(~(1<<i));
    }

    sbit = sbit&(~(1<<s));

    dP[sbit] = minNow;
    return minNow;
}

int main() {
    int t=1,a,b;
    string str;
    string c;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while(n) {
        cin>>n;
        init(n);

        for(int i=0; i<2*n; i++) {
            cin>>str>>a>>b;
            dist[i].first = a;
            dist[i].second = b;
        }

        if(n) printf("Case %d: %0.2f\n",t++,findMinDist(dist, 0));
    }
}
