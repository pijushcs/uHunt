#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

vector<int> vnum;
map<iii, long long> dP;

long long countSets(int pos, int n, int d, int m, int dsum) {
    if(m==0 && dsum==0) return 1;
    if(pos==n || m==0) return 0;

    long long res=dP[iii(ii(dsum%d, m), pos)];
    if(res!=0) return res;

    res=countSets(pos+1, n, d, m-1, (dsum%d+vnum[pos]%d)%d)
        + countSets(pos+1, n, d, m, dsum);

    dP[iii(ii(dsum%d, m), pos)]=res;
    return res;
}

int main() {
    int n, q, m, d, tcase=1;
    int val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n>>q;
    while(n!=0 && q!=0) {
        vnum.clear();
        for(int i=0; i<n; i++) {
            cin>>val; vnum.push_back(val);
        }

        cout<<"SET "<<tcase++<<":"<<endl;

        int tquery=1;
        for(int i=0; i<q; i++) {
            cin>>d>>m;

            dP.clear();
            cout<<"QUERY "<<tquery++<<": "<<countSets(0,n,d,m,0)<<endl;
        }

        cin>>n>>q;
    }
}
