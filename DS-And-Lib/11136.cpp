#include<iostream>
#include<set>
using namespace std;

long long sumHoax(int nDays) {
    long long res=0, n, k;
    multiset<long long> setMart;

    for(int i=0; i<nDays; i++) {
        cin>>n;
        for(int j=0; j<n; j++) {
            cin>>k;
            setMart.insert(k);
        }
        res+=(*(setMart.rbegin()) - *(setMart.begin()));
        if(!setMart.empty()) setMart.erase(setMart.begin());
        if(!setMart.empty()) setMart.erase(--setMart.end());
    }

    return res;
}

int main() {
    int nDays;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);
    cin>>nDays;
    while(nDays!=0) {
        cout<<sumHoax(nDays)<<endl;
        cin>>nDays;
    }
}
