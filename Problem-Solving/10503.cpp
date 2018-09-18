#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;

typedef pair<int,int> ii;

vector<ii> vdom;
ii dfirst, dend;

bitset<20> bdom;

bool checkGame(int n, int m, int padj) {
    if(n==0) {
        if(padj==dend.first) return true;
        return false;
    }

    for(int i=0; i<m; i++) {
        if(bdom.test(i)==false) {
            if(vdom[i].first==padj) {
                bdom.set(i); //cout<<i<<":("<<vdom[i].first<<","<<vdom[i].second<<") ";
                if(checkGame(n-1, m, vdom[i].second))
                    return true;
                bdom.reset(i);
            }
            else if(vdom[i].second==padj) {
                bdom.set(i); //cout<<i<<":("<<vdom[i].second<<","<<vdom[i].first<<") ";
                if(checkGame(n-1, m, vdom[i].first) )
                    return true;
                bdom.reset(i);
            }
        }
    }

    return false;
}

int main() {
    int n,m,p,q;

    freopen("testCase.txt", "r", stdin);

    cin>>n;
    while(n) {
        cin>>m;

        cin>>p>>q; dfirst=ii(p,q);
        cin>>p>>q; dend=ii(p,q);

        vdom.clear();
        for(int i=0; i<m; i++) {
            cin>>p>>q;
            vdom.push_back(ii(p,q));
        }

        bdom.reset();
        if(checkGame(n,m,dfirst.second)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        cin>>n;
    }
}
