#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

bool isFill(vector<ll> &vesx, ll cap, ll m) {
    ll curCont=0, curCap=0;

    for(int i=0; i<vesx.size(); i++) {
        if(curCap<vesx[i]) {
            curCont++;
            curCap=cap;
        }

        if(curCont>m) return false;
        curCap-=vesx[i];
    }

    return true;
}

ll findCapacity(vector<ll> &vesx, ll lo, ll hi, ll m) {
    long long mid, res=1e+8;
    while(lo<=hi) {
        mid=(lo+hi)/2;

        if(isFill(vesx, mid, m)) {
            res=min(res, mid);
            hi=mid-1;
        }
        else
            lo=mid+1;
    }

    return res;
}

int main() {
    ll n, m, vsum, vmax, val;
    vector<ll> vesx;

    while((cin>>n)) {
        cin>>m;

        vsum=0; vmax=0;
        vesx.clear();

        for(int i=0; i<n; i++) {
            cin>>val; vesx.push_back(val);
            vsum+=val; vmax=max(vmax, vesx[i]);
        }

        cout<<findCapacity(vesx, vmax, vsum, m)<<endl;
    }
}
