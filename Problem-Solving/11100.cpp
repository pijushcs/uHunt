#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t,n,npot,tpot,pos;
    long long val,pval;

    vector<vector<long long> > vbag;
    vector<long long> vpot;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n;
    while(n!=0) {

        vpot.clear();
        pval=0; npot=0; pos=0;
        for(int i=0; i<n; i++) {
            cin>>val; vpot.push_back(val);
        }

        sort(vpot.begin(), vpot.end());
        for(int i=0; i<n; i++) {
            val=vpot[i];
            if(val!=pval) tpot=1;
            else tpot++;

            pval=val;
            npot=max(npot, tpot);
        }

        vbag.assign(npot, vector<long long>());
        for(int i=0; i<vpot.size(); i++) {
            vbag[pos].push_back(vpot[i]);
            pos=(pos+1)%npot;
        }

        cout<<npot<<endl;
        for(int i=0; i<npot; i++) {
            for(int j=0; j<vbag[i].size(); j++) {
                if(j!=0) cout<<" ";
                cout<<vbag[i][j];
            }
            cout<<endl;
        }

        cin>>n;
        if(n) cout<<endl;
    }
}
