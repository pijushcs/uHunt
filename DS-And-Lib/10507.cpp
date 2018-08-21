#include<iostream>
#include<vector>
using namespace std;

vector<bool> nvis, vis;
vector<vector<int> > adjList;

int findYears(int n) {
    int ycur=0, ncur=3;
    vector<int> tnode;
    bool flgUpdate=true;

    while(flgUpdate && ncur<n) {
        flgUpdate=false;
        tnode.clear();

        for(int i=0; i<nvis.size(); i++) {
            if(nvis[i]==true) {
                int ncnt=0;
                for(int j=0; j<adjList[i].size(); j++) {
                    if(vis[adjList[i][j]]==true) ncnt++;
                }
                if(ncnt>=3) {
                    tnode.push_back(i); nvis[i]=false;
                    flgUpdate=true;
                }
            }
        }
        ncur+=tnode.size();
        for(int i=0; i<tnode.size(); i++) vis[tnode[i]]=true;
        ycur++;
    }

    if(ncur==n) return ycur;
    return -1;
}

int main() {
    int n, p;
    char a,b,c;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);
    while((cin>>n)) {
        cin>>p;

        vis.assign(30, false);
        nvis.assign(30, false);
        adjList.assign(30, vector<int>());

        cin>>a>>b>>c;
        vis[a-'A']=true; vis[b-'A']=true; vis[c-'A']=true;

        while(p--) {
            cin>>a>>b;
            if(vis[a-'A']==false) nvis[a-'A']=true;
            if(vis[b-'A']==false) nvis[b-'A']=true;

            adjList[a-'A'].push_back(b-'A');
            adjList[b-'A'].push_back(a-'A');
        }

        int res=findYears(n);
        if(res==-1) cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
        else cout<<"WAKE UP IN, "<<res<<", YEARS"<<endl;
    }
}


