#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<map>
using namespace std;

typedef pair<int,int> ii;
priority_queue<ii, vector<ii>, greater<ii> > pQuery;
map<int, int> mPeriod;

void printQuery(int n) {
    while(n--) {
        ii val=pQuery.top(); pQuery.pop();
        cout<<val.second<<endl;

        val.first=val.first + mPeriod[val.second];
        pQuery.push(val);
    }
}

int main() {
    string regx;
    int qm, prd, n;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>regx;
    while(regx.compare("#")) {
        cin>>qm>>prd;
        mPeriod[qm]=prd;
        pQuery.push(ii(prd, qm));
        cin>>regx;
    }

    cin>>n;
    printQuery(n);
}
