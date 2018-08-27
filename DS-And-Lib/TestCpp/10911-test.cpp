#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<map>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef pair<long double, long double> ii;

vector<ii> scord;
bitset<20> sbits;
hash<bitset<20> > hashx;
map<size_t, double> dP;
map<size_t, bool> dPSet;

long double calDist(int a, int b) {
    ii u=scord[a], v=scord[b];
    return sqrt((u.first-v.first)*(u.first-v.first)+(u.second-v.second)*(u.second-v.second));
}

double getDist(int pos) {
    if(pos>=scord.size()) return 0;

    if(dPSet[hashx(sbits)]==true) return dP[hashx(sbits)];
    if(sbits[pos]==1) return getDist(pos+1);

    sbits[pos]=1;
    long double minNow=99999999;
    for(int i=pos+1; i<scord.size(); i++) {
        if(sbits[i]==1) continue;

        sbits[i]=1;
        minNow=min(calDist(pos, i)+getDist(pos+1), minNow);
        sbits[i]=0;
    }

    sbits[pos]=0;
    dP[hashx(sbits)]=minNow;
    dPSet[hashx(sbits)]=true;

    return minNow;
}

int main() {
    int n,k=1;
    string stName;
    double x,y;

    freopen("testCase.txt", "r", stdin);
    //freopen("testOut.txt", "w", stdout);

    cin>>n;
    while(n!=0) {
        scord.clear();
        dP.clear();
        dPSet.clear();
        sbits.reset();

        for(int i=0; i<2*n; i++) {
            cin>>stName>>x>>y;
            scord.push_back(ii(x,y));
        }

        printf("Case %d: %0.2f\n",k++,getDist(0));
        cin>>n;
    }
}
