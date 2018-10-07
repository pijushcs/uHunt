#include<iostream>
#include<vector>
using namespace std;

typedef pair<long long, long long> ll;

vector<ll> vprod;
vector<vector<long long> > dP;
long long p;

long long maxProd(int pos, long long curp) {
    if((p>1800 && curp>p+200) || (p<=1800 && curp>p)) return -1000000000;
    if((p>1800 && curp==p+200) || (p<=1800 && curp==p)) return 0;

    if(pos==vprod.size()) {
        if(curp>p && curp>2000 && curp<=p+200) return 0;
        if(curp<=p) return 0;

        if(curp>p && curp<=2000) return -1000000000;
        if(p<=1800 && curp>p) return -1000000000;
    }

    if(dP[pos][curp]!=-1) return dP[pos][curp];

    dP[pos][curp] = max(maxProd(pos+1, curp), vprod[pos].second + maxProd(pos+1, curp+vprod[pos].first));
    return dP[pos][curp];
}

int main() {
    long long curp, val;
    int m;

    while((cin>>p)) {
        cin>>m;

        vprod.clear();
        dP.assign(m, vector<long long>());

        for(int i=0; i<m; i++) {
            cin>>curp>>val;
            vprod.push_back(ll(curp, val));
            dP[i].assign(p+300, -1);
        }

        long long resx = maxProd(0, 0);
        cout<<resx<<endl;
    }
}
