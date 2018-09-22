#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

vector<vi> vmat;
int l, u;

int findMaxSize(int n, int m) {
    vector<ii> vpos;
    int csize=0, rsize=0;

    for(int i=0; i<n; i++) {
        vi::iterator ilpos=lower_bound(vmat[i].begin(), vmat[i].end(), l);
        vi::iterator irpos=upper_bound(vmat[i].begin(), vmat[i].end(), u);

        vpos.push_back(ii(ilpos-vmat[i].begin(), irpos-vmat[i].begin()-1));
    }

    for(int i=0; i<n; i++) {
        int lpos=vpos[i].first, rpos=vpos[i].second;
        int csize=0;

        for(int j=i; j<i+(rpos-lpos+1); j++) {
            if(vpos[j].first>rpos || vpos[j].second<lpos || j>=n)
                break;

            if(vpos[j].first>lpos) lpos=vpos[j].first;
            if(vpos[j].second<rpos) rpos=vpos[j].second;

            csize=min(rpos-lpos+1, j-i+1);
            rsize=max(csize, rsize);
        }
    }

    return rsize;
}

int main() {
    int n, m, nq, val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut-2.txt", "w", stdout);

    cin>>n>>m;
    while(n!=0 && m!=0) {
        vmat.clear();
        for(int i=0; i<n; i++) {
            vmat.push_back(vi());
            for(int j=0; j<m; j++) {
                cin>>val; vmat[i].push_back(val);
            }
        }

        cin>>nq;
        while(nq--) {
            cin>>l>>u;
            cout<<findMaxSize(n, m)<<endl;
        }

        cout<<"-"<<endl;
        cin>>n>>m;
    }
}
