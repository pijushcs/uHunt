#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef vector<int> vi;

vi vres, vset, vcolor;
vector<vi> adjList;
int maxNow=0;

void colorGraph(int p, int n) {
    bool bflag=false;

    if(p>n) {
        if(maxNow<vset.size()) {
            maxNow=vset.size();
            vres=vset;
        }

        return;
    }

    for(int i=0; i<adjList[p].size(); i++) {
        int v=adjList[p][i];
        if(vcolor[v]==1) { bflag=true; break; }
    }

    if(!bflag) {
        vcolor[p]=1; // 1 is black
        vset.push_back(p);
        colorGraph(p+1, n);
        vset.pop_back();
    }

    vcolor[p]=0;
    colorGraph(p+1, n);
}

int main() {
    int t,n,m,u,v;

    freopen("testCase.txt", "r", stdin);

    cin>>t;
    while(t--) {
        cin>>n>>m;

        adjList.assign(n+1, vi());
        for(int i=0; i<m; i++) {
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vcolor.assign(n+1, -1);
        maxNow=0;

        colorGraph(1,n);

        cout<<maxNow<<endl;

        cout<<vres[0];
        for(int i=1; i<vres.size(); i++)
            cout<<" "<<vres[i];
        cout<<endl;
    }
}
