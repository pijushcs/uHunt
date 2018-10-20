#include<iostream>
#include<vector>
using namespace std;

/*******************************************************************************
* Suppose {1...i} is in the coins collected list While selecting (i+1)th coin, *
* we must check if sum(selected-coins{1..i})+vcoins[i+1]<the next coin If this *
* is true, selecting (i+1)th coin will be fine. Otherwise, selecting the (i+1) *
* coin will force the next coin to take place                                  *
* Note(1): We cannot simply check sum(selected-coins{1..i})<vcoins[i+1] while  *
* selecting (i+1)th coin, since the next coin(if less than the sum) can take   *
* its place and we must consider it like above                                 *
* Note(2): The last coin will always be on the selected-coins list since       *
* the current selected-coins list {1..i} has sum(..)<the next coins<last coins *
*******************************************************************************/
int findCoins(vector<long long> &vcoins) {
    int ncoins, mcoins=0;
    long long csum;

    for(int i=0; i<vcoins.size(); i++) {
        ncoins=1; csum=vcoins[i];

        for(int j=i+1; j<vcoins.size(); j++) {
            if(j<vcoins.size()-1 && csum+vcoins[j]<vcoins[j+1]) {
                csum+=vcoins[j];
                ncoins++;
            }
            else if(j==vcoins.size()-1)
                ncoins++;
        }

        mcoins=max(ncoins, mcoins);
    }

    return mcoins;
}

int main() {
    int t,n;
    long long val;
    vector<long long> vcoins;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n;

        vcoins.clear();
        for(int i=0; i<n; i++) {
            cin>>val; vcoins.push_back(val);
        }

        cout<<findCoins(vcoins)<<endl;
    }
}
