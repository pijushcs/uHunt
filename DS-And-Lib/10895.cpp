#include<iostream>
#include<vector>
using namespace std;

typedef pair<long long, long long> ii;
vector<vector<ii> > cPos;
vector<vector<long long> > rPos;

int main() {
    long long r, c, m, pos;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>r>>c)) {
        rPos.assign(r+1, vector<long long>());
        cPos.assign(c+1, vector<ii>());

        for(int i=1; i<=r; i++) {
            cin>>m;
            for(int j=0; j<m; j++) {cin>>pos; rPos[i].push_back(pos);}
            for(int j=0; j<m; j++) {cin>>pos; cPos[rPos[i][j]].push_back(ii(i,pos));} //pos is the val
        }

        cout<<c<<" "<<r<<endl;

        for(int i=1; i<=c; i++) {
            cout<<cPos[i].size();

            for(int j=0; j<cPos[i].size(); j++) cout<<" "<<cPos[i][j].first;
            cout<<endl;

            for(int j=0; j<cPos[i].size(); j++) {if(j!=0) cout<<" "; cout<<cPos[i][j].second;}
            cout<<endl;
        }
    }
}
