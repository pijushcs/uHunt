#include<iostream>
#include<set>
using namespace std;

set<long long> setCd;

int main() {
    long long m, n, cd, res;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>m>>n;
    while(m!=0 || n!=0) {
        setCd.clear();
        res=0;

        while(m--) {
            cin>>cd;
            setCd.insert(cd);
        }

        while(n--) {
            cin>>cd;
            if(setCd.find(cd)!=setCd.end()) res++;
        }

        cout<<res<<endl;
        cin>>m>>n;
    }
}
