#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    long long val, pprev, maxNow;
    vector<long long> vprod;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>val)) {
        maxNow=-100000000;
        pprev=1; vprod.clear();

        while(val!=-999999) {
            vprod.push_back(pprev*val);

            if(val==0) pprev=1;
            else pprev=pprev*val;

            cin>>val;
        }

        for(int i=0; i<vprod.size(); i++) {
            if(i==0 || vprod[i-1]==0) pprev=1;
            else pprev=vprod[i-1];

            maxNow=max(maxNow, vprod[i]);
            for(int j=i; j<vprod.size(); j++) {
                if(vprod[j]==0) break;
                maxNow=max(maxNow, vprod[j]/pprev);
            }
        }

        cout<<maxNow<<endl;
    }
}
