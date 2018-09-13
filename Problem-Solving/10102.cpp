#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

typedef pair<int,int> ii;

int main() {
    int m,val;
    string tstr;
    vector<ii> spos, epos;

    freopen("testCase.txt","r",stdin);
    freopen("testOut.txt","w",stdout);
    while((cin>>m)) {
        spos.clear();
        epos.clear();

        for(int i=0; i<m; i++) {
            cin>>tstr;
            for(int j=0; j<m; j++) {
                int val=tstr[j]-'0';
                if(val==1) spos.push_back(ii(i,j));
                if(val==3) epos.push_back(ii(i,j));
            }
        }

        int maxNow=0;
        for(int i=0; i<spos.size(); i++) {
            ii st=spos[i];
            int minNow=3*m;
            for(int j=0; j<epos.size(); j++) {
                ii et=epos[j];
                minNow=min(minNow, abs(st.first-et.first)+abs(st.second-et.second));
            }
            maxNow=max(maxNow,minNow);
        }

        cout<<maxNow<<endl;
    }
}
