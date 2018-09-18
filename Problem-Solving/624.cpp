#include<iostream>
#include<vector>
using namespace std;

vector<int> tres, vres, vtrack;
int maxNow;

void findSet(int n, int m, int p, int cSum) {
    if(cSum>n || p>m) return;
    if(p==m || cSum==n) {
        if(maxNow<cSum) {
            maxNow=cSum;
            vres=tres;
        }
    }

    tres.push_back(p);
    findSet(n, m, p+1, cSum+vtrack[p]);
    tres.pop_back();

    findSet(n, m, p+1, cSum);
}

int main() {
    int n,m,val;

    while((cin>>n)) {
        cin>>m;

        vtrack.clear(); tres.clear(); vres.clear();
        maxNow=0;

        for(int i=0; i<m; i++) {
            cin>>val;
            vtrack.push_back(val);
        }

        findSet(n, m, 0, 0);
        for(int i=0; i<vres.size(); i++)
            cout<<vtrack[vres[i]]<<" ";
        cout<<"sum:"<<maxNow<<endl;
    }
}
