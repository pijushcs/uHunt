#include<iostream>
#include<map>
using namespace std;

map<long long, long long> mpos;

long long computeMap(long long n) {
    long long pos=1;

    if(mpos[n]!=0)
        return mpos[n];

    while(n!=1) {
        if(n%2==0) n=n/2;
        else n=3*n+1;
        pos++;
    }

    mpos[n]=pos;
    return pos;
}

int main() {
    long long i, j, n, m;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    mpos.clear();
    while((cin>>i)) {
        cin>>j;
        n=min(i,j);
        m=max(i,j);

        long long pmax=0;
        while(n<=m) {
            long long pos = computeMap(n);
            pmax = max(pmax, pos);
            n++;
        }

        cout<<i<<" "<<j<<" "<<pmax<<endl;
    }
}
