#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, int> ii;

map<ii, long long> dP;

// Doesn't fit in long long too
long long nCk(int n, int k) {
    if(n==0 && k==0) return 1;
    if(n<=0 || k<0) return 0;

    if(dP.find(ii(n,k))!=dP.end()) return dP[ii(n,k)];
    long long res=nCk(n-1, k-1) + nCk(n-1, k);

    dP[ii(n,k)]=res;
    return res;
}

// The trick is given below:
// log(n!/k!*(n-k)) = log(n!) - (log(k!)+log(n-k)!)
// Now, log(n*n-1*n-2*n-3...*1) = log(n)+log(n-1)+...+log(1);
int numDigits(int n, int k) {
    double nLog=0, kLog=0, nkLog=0;

    for(int i=1; i<=n; i++) {
        nLog+=log10(i);
        if(i==k) kLog=nLog;
        if(i==n-k) nkLog=nLog;
    }

    return (int)floor(nLog-(kLog+nkLog) + 1);
}

int main() {
    int n, k;

    while((cin>>n)) {
        cin>>k;

        dP.clear();
        int res=numDigits(n,k);

        cout<<res<<endl;
    }
}
