#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<cmath>
#include<algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, long long> iii;
vector<iii> vcity;

long long checkSol(bitset<30> &city) {
    long long tmin=0;

    for(int i=0; i<vcity.size(); i++) {
        ii cpos=vcity[i].first;

        int cmin=100000;
        for(int j=0; j<25; j++) {
            int r=j/5, c=(j-5*r);
            if(city.test(j))
                cmin=min(cmin,abs(cpos.first-r)+abs(cpos.second-c));
        }

        tmin+=(cmin*vcity[i].second);
    }

    return tmin;
}

long long minNow=10000000000;
string rstr;
void findMinSol(bitset<30> &city, int p, int nset) {
    if(nset==5) {
        long long res=checkSol(city);
        if(minNow>res) {
            minNow=res;
            rstr=city.to_string();
            reverse(rstr.begin(), rstr.end());
        }

        return;
    }

    if(p==25) return;

    city[p]=true;
    findMinSol(city, p+1, nset+1);
    city[p]=false;
    findMinSol(city, p+1, nset);
}

int main() {
    int t,n,r,c,v;
    bitset<30> city;

    cin>>t;
    while(t--) {
        cin>>n;
        vcity.clear();
        minNow=10000000000;


        for(int i=0; i<n; i++) {
            cin>>r>>c>>v;
            vcity.push_back(iii(ii(r,c),v));
        }

        findMinSol(city, 0, 0);

        bool pflag=false;
        for(int i=0; i<25; i++) {
            if(rstr[i]=='1') {
                if(pflag) cout<<" ";
                cout<<i;
                pflag=true;
            }
        }
        cout<<endl;
    }
}
