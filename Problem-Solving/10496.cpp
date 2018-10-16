#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

#define INF 100000000000

typedef pair<int, int> ii;

long long dP[11][2048];
vector<ii> vbeep;

long long scal(int a, int b) {
    return (abs(vbeep[a].first - vbeep[b].first) +
        abs(vbeep[a].second- vbeep[b].second));
}

long long findSteps(int pos, int bmask, int n) {
    long long smin = INF;

    if(bmask==(pow(2,n)-1))
        return scal(pos, n);

    if(dP[pos][bmask]!=-1)
        return dP[pos][bmask];

    for(int i=0; i<n; i++) {
        if((bmask&(1<<i)) == 0) {
            bmask=bmask|(1<<i);
            smin = min(smin, scal(pos, i) + findSteps(i, bmask, n));
            bmask=bmask^(1<<i);
        }
    }

    dP[pos][bmask] = smin;
    return smin;
}

int main() {
    int t,n, sx,sy,x,y;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>sx>>sy; cin>>sx>>sy;

        cin>>n;
        vbeep.clear();
        for(int i=0; i<n; i++) {
            cin>>x>>y;
            vbeep.push_back(ii(x,y));
            memset(dP[i], -1, 2048*sizeof(long long));
        }
        vbeep.push_back(ii(sx,sy));
        memset(dP[n], -1, 2048*sizeof(long long));

        int bmask=0;
        cout<<"The shortest path has length "<<findSteps(n,bmask,n)<<endl;
    }
}
