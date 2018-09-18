#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

vector<int> vzone, vres, tzone, vzoneVal;
map<vector<int>, long long> mzone;

bitset<100> bzone;

long long maxNow;
string delim="x";

void checkMaxCovered(int m) {
    long long res=0;

    for(int i=0; i<m; i++) {
        res+=vzoneVal[vzone[i]-1];
    }

    for(map<vector<int>, long long>::iterator it=mzone.begin(); it!=mzone.end(); it++) {
        vector<int> tres=it->first;
        int tzoneSize=0;

        for(int i=0; i<tres.size(); i++)
            if(bzone.test(tres[i]))
                tzoneSize++;

        if(tzoneSize)
            res=res-((tzoneSize-1)*(it->second));
    }

    if(maxNow<res) {
        vres=vzone;
        maxNow=res;
    }
}

//nCm
void findZone(int n, int nm, int m, int p) {
    if(m==0) {
        checkMaxCovered(nm);
        return;
    }

    if(p>n) return;

    vzone.push_back(p); bzone.set(p);
    findZone(n,nm, m-1,p+1);
    vzone.pop_back(); bzone.reset(p);

    findZone(n,nm, m,p+1);
}

int main() {
    int n,m,t,nc, tcase=1;
    long long val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n>>m;
    while(n!=0 && m!=0) {
        //if(tcase>1) cout<<endl;

        vzoneVal.clear();
        for(int i=0; i<n; i++) {
            cin>>val; vzoneVal.push_back(val);
        }

        cin>>nc;
        mzone.clear();
        for(int i=0; i<nc; i++) {
            cin>>t;

            tzone.clear();
            for(int j=0; j<t; j++) {
                cin>>val; tzone.push_back(val);
            }

            cin>>val;
            mzone[tzone]=mzone[tzone]+val;
        }

        tzone.clear(); vzone.clear(); vres.clear(); bzone.reset();
        maxNow=0;

        findZone(n, m, m, 1);

        cout<<"Case Number  "<<tcase++<<endl;
        cout<<"Number of Customers: "<<maxNow<<endl;
        cout<<"Locations recommended: "<<vres[0];

        for(int i=1; i<vres.size(); i++) cout<<" "<<vres[i];
        cout<<endl<<endl;

        cin>>n>>m;
    }
}
