#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<bitset>
using namespace std;

#define INF 100000.0

double adjList[60][60], dP[60][4097], asave[60];
vector<int> vnode;

void initList(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            adjList[i][j]=INF;
        adjList[i][i]=0.0;
    }
}

void initNode(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<4097; j++)
            dP[i][j]=-1.0;
        asave[i]=0.0;
    }
}

void floydWarshall(int n) {
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                adjList[i][j]=min(adjList[i][j], adjList[i][k]+adjList[k][j]);
}

double dvdProfit(int pos, int p, int bmask) {
    double mprofit=-INF;
    if(bmask==pow(2,p)-1) return -(adjList[pos][0]);

    if(dP[pos][bmask]!=-1.0)
        return dP[pos][bmask];

    for(int i=0; i<p; i++) {
        if((bmask&(1<<i))!=0) continue;
        int v=vnode[i];

        bmask=(bmask|(1<<i));
        mprofit=max(mprofit,
                    max(asave[v]-adjList[pos][v]+dvdProfit(v, p, bmask),
                        dvdProfit(pos,p,bmask)));
        bmask=(bmask^(1<<i));
    }

    dP[pos][bmask]=mprofit;
    return mprofit;
}

int main() {
    int t,n,p,m,u,v, ptemp;
    double d;

    bitset<60> btemp;

    //freopen("testCase.txt", "r", stdin);
    //freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n>>m;
        initList(n+1);
        initNode(n+1);

        for(int i=0; i<m; i++) {
            cin>>u>>v>>d;
            adjList[u][v]=min(adjList[u][v],d);
            adjList[v][u]=min(adjList[u][v],d);
        }

        floydWarshall(n+1);

        cin>>ptemp; btemp.reset();
        for(int i=0; i<ptemp; i++) {
            cin>>v>>d;
            btemp.set(v);
            asave[v]+=d;
        }

        p=btemp.count();
        vnode.clear();
        for(int i=1; i<=n; i++)
            if(btemp.test(i)) vnode.push_back(i);

        double res = dvdProfit(0, p, 0);

        if((res-0.0)>1e-7) printf("Daniel can save $%0.2f\n", res);
        else printf("Don't leave the house\n");
    }
}
