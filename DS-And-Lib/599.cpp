#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;

vb vis, vcur;
vector<vi> adjList;

void dfs(int u) {
    if(vis[u]) return;

    vis[u]=true;
    for(int i=0; i<adjList[u].size(); i++) {
        int v=adjList[u][i];
        if(vis[v]==false) dfs(v);
    }
}

int main() {
    string str;
    int n, nTree, nAcron;
    char u, v;

    freopen("testCase.txt", "r", stdin);

    cin>>n; getline(cin, str);
    while(n--) {
        vis.assign(30, false);
        vcur.assign(30, false);
        nTree=0; nAcron=0;

        adjList.assign(30, vi());

        getline(cin, str);
        while(str[0]!='*') {
            sscanf(str.c_str(), "(%c,%c)", &u, &v);
            adjList[u-'A'].push_back(v-'A');
            adjList[v-'A'].push_back(u-'A');

            getline(cin, str);
        }

        getline(cin, str);
        for(int i=0; i<str.length(); i=i+2)
            vcur[str[i]-'A']=true;

        for(int i=0; i<vcur.size(); i++) {
            if(vcur[i]==true && vis[i]==false) {
                if(adjList[i].size()==0) nAcron++;
                else nTree++;
                dfs(i);
            }
        }

        printf("There are %d tree(s) and %d acorn(s).\n", nTree, nAcron);
    }
}
