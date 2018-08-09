#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef pair<long long, long long> ii;

map<long long, long long> kVal; // stores largest kth index for val
map<ii, long long> kIndex; // stores position for kth index of val

int main() {
    long long n, m, cPos=1, k, val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>n>>m)) {
        cPos=1;
        kVal.clear(); kIndex.clear();

        while(n--) {
            cin>>val;
            kVal[val]=kVal[val]+1;
            kIndex[ii(val,kVal[val])]=cPos++;
        }

        while(m--) {
            cin>>k>>val;

            if(k>kVal[val]) cout<<0<<endl;
            else cout<<kIndex[ii(val,k)]<<endl;
        }
    }
}
