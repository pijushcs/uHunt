#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<long long, long long> ll;

vector<long long> hSky, wSky;
vector<ll> maxSky;

ll findSkyline() {
    long long maxAsc=0, maxDes=0;
    int n=hSky.size();

    for(int i=0; i<n; i++) {
        long long curAsc=wSky[i], curDes=wSky[i];

        for(int j=0; j<i; j++) {

            if(hSky[i]>hSky[j]) curAsc=max(curAsc, maxSky[j].first+wSky[i]);
            if(hSky[i]<hSky[j]) curDes=max(curDes, maxSky[j].second+wSky[i]);
        }

        maxSky.push_back(ll(curAsc, curDes));

        maxAsc=max(maxAsc, curAsc);
        maxDes=max(maxDes, curDes);
    }

    return ll(maxAsc, maxDes);
}

int main() {
    int t, n, tcase=1;
    long long val;

    freopen("testCase.txt", "r", stdin);

    cin>>t;
    while(t--) {
        cin>>n;

        hSky.clear(); wSky.clear(); maxSky.clear();
        for(int i=0; i<n; i++) {
            cin>>val; hSky.push_back(val);
        }

        for(int i=0; i<n; i++) {
            cin>>val; wSky.push_back(val);
        }

        ll res=findSkyline();
        if(res.first>=res.second) cout<<"Case "<<tcase++<<". Increasing ("<<res.first<<"). Decreasing ("<<res.second<<")."<<endl;
        else cout<<"Case "<<tcase++<<". Decreasing ("<<res.second<<"). Increasing ("<<res.first<<")."<<endl;
    }
}
