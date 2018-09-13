#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int dr[]={0,1,0,-1};
int dc[]={-1,0,1,0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;

vector<vi> field;

int bfs(int kr, int kc, int m, vector<vb> &vis) {
    queue<iii> qbfs;

    qbfs.push(iii(0,ii(kr,kc)));
    while(!qbfs.empty()) {
        iii cell=qbfs.front();
        int r=cell.second.first, c=cell.second.second;
        int cdist=cell.first;

        vis[r][c]=true;
        qbfs.pop();
        if(field[r][c]==3) return cdist;

        for(int i=0; i<4; i++) {
            int tr=r+dr[i], tc=c+dc[i];
            if(tr<0 || tc<0 || tr>=m || tc>=m) continue;
            if(vis[tr][tc]==false) qbfs.push(iii(cdist+1,ii(tr, tc)));
        }
    }

    return 0;
}

int main() {
    int m,val;
    string tstr;
    vector<vb> vis;
    vector<ii> posx;

        freopen("testCase.txt","r",stdin);
    freopen("testOut.txt","w",stdout);
    while((cin>>m)) {
        field.clear();
        posx.clear();
        field.assign(m,vi());

        for(int i=0; i<m; i++) {
            cin>>tstr;
            for(int j=0; j<m; j++) {
                val=tstr[j]-'0';
                if(val==1) posx.push_back(ii(i,j));
                field[i].push_back(val);
            }
        }

        vis.assign(m,vb());
        for(int i=0; i<m; i++)
            vis[i].assign(m, false);

        int maxNow=0;
        for(int i=0; i<posx.size(); i++) {
            ii pos=posx[i];
            maxNow=max(maxNow, bfs(pos.first, pos.second, m, vis));
        }

        cout<<maxNow<<endl;
    }
}
