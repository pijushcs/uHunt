#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long maxGold(vector<long long> &vdragon, vector<long long> &vknight) {
    int dpos=0, kpos=0;
    long long ngold = 0;
    if(vdragon.size()>vknight.size()) return -1;

    while(dpos<vdragon.size() && kpos<vknight.size()) {
        if(vknight[kpos]>=vdragon[dpos]) {
            kpos++; dpos++;
            ngold+=vknight[kpos-1];
        }
        else kpos++;
    }

    if(dpos==vdragon.size()) return ngold;
    return -1;
}

int main() {
    int d,k;
    long long val;

    vector<long long> vdragon, vknight;

    cin>>d>>k;
    while(d!=0 && k!=0) {
        vdragon.clear();
        for(int i=0; i<d; i++) {
            cin>>val; vdragon.push_back(val);
        }

        vknight.clear();
        for(int i=0; i<k; i++) {
            cin>>val; vknight.push_back(val);
        }

        sort(vdragon.begin(), vdragon.end());
        sort(vknight.begin(), vknight.end());

        long long res = maxGold(vdragon, vknight);
        if(res!=-1) cout<<res<<endl;
        else cout<<"Loowater is doomed!"<<endl;

        cin>>d>>k;
    }
}
