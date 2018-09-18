#include<iostream>
#include<bitset>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int alex=1;
int bob=2;

typedef pair<string, string> ii;
typedef pair<int, ii> iii;

map<ii,long long> dP;

long long findMaxMin(int grid[10][10], int m, bitset<10> &balex, bitset<10> &bbob, int puser, int ralex) {
    bool tcheck=false;
    for(int i=0; i<m; i++)
        if(bbob.test(i)==false) tcheck=true;

    if(!tcheck) return 0;

    if(puser==alex && dP[ii(balex.to_string(), bbob.to_string())]!=0)
       return dP[ii(balex.to_string(), bbob.to_string())];

    if(puser==alex) {
        long long maxNow=-100000000;

        for(int i=0; i<m; i++) {
            if(balex.test(i)==false) {
                balex.set(i);
                maxNow=max(maxNow, findMaxMin(grid, m, balex, bbob, bob, i));
                balex.reset(i);
            }
        }

        dP[ii(balex.to_string(), bbob.to_string())]=maxNow;
        return maxNow;
    }
    else {
        long long minNow=100000000;

        for(int i=0; i<m; i++) {
            if(bbob.test(i)==false) {
                bbob.set(i);
                minNow=min(minNow, grid[ralex][i]+findMaxMin(grid, m, balex, bbob, alex, 0));
                bbob.reset(i);
            }
        }

        return minNow;
    }

    return 0;
}

int main() {
    int t,m;
    bitset<10> balex, bbob;
    int grid[10][10];

    cin>>t;
    while(t--) {
        cin>>m;
        dP.clear();
        bbob.reset(); balex.reset();

        for(int i=0; i<m; i++)
            for(int j=0; j<m; j++)
                cin>>grid[i][j];

        cout<<findMaxMin(grid, m, balex, bbob, alex, 0)<<endl;
    }
}
