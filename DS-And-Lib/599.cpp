#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

typedef pair<int, int> ii;

map<char, vector<char> > adjMap;
map<char, bool> visMap;
vector<char> vNode;

void findComponent(char c) {
    visMap[c]=true;
    for(int i=0; i<adjMap[c].size(); i++) {
        char nxtV=adjMap[c][i];
        if(visMap[nxtV]==false) findComponent(nxtV);
    }
    return;
}

ii findTreeAcron() {
    int resTree=0, resAcron=0;
    for(int i=0; i<vNode.size(); i++) {
        if(visMap[vNode[i]]==false) {
            findComponent(vNode[i]);

            if(adjMap[vNode[i]].size()>0) resTree++;
            else resAcron++;
        }
    }

    return ii(resTree, resAcron);
}

int main() {
    int n;
    char vx, vy;
    string str;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n; getline(cin, str);
    while(n--) {
        adjMap.clear();
        vNode.clear();
        visMap.clear();

        getline(cin, str);
        while(str[0]!='*') {
            sscanf(str.c_str(), "(%c,%c)", &vx, &vy);
            adjMap[vx].push_back(vy);
            adjMap[vy].push_back(vx);
            getline(cin, str);
        }

        getline(cin, str);
        for(int i=0; i<str.length(); i+=2) {
            vx=str[i];
            visMap[vx]=false;
            vNode.push_back(vx);
        }

        ii res=findTreeAcron();
        cout<<"There are "<<res.first<<" tree(s) and "<<res.second<<" acorn(s)."<<endl;
    }
}
