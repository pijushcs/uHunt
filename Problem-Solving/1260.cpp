#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t,n,csale;
    long long tsale;
    vector<int> vsale;

    cin>>t;
    while(t--) {
        cin>>n;

        tsale=0;
        vsale.clear();
        for(int i=0; i<n; i++) {
            cin>>csale; vsale.push_back(csale);
            for(int j=0; j<i; j++)
                if(vsale[j]<=csale) tsale++;
        }

        cout<<tsale<<endl;
    }
}
