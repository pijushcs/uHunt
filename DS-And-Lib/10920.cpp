#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

ii findVal(long nCor, long long n, long long val) {
    long long nPow=n*n;
    int r=nCor, c=nCor;

    if(n==1) return ii(r,c);

    for(int i=0; i<n; i++){
        if(nPow==val) return ii(r,c);
        if(i!=n-1) { r--; nPow--; }
    }

    c--; nPow--;
    for(int i=0; i<n-2; i++){
        if(nPow==val) return ii(r,c);
        if(i!=n-3) { c--; nPow--; }
    }

    c--; nPow--;
    for(int i=0; i<n; i++){
        if(nPow==val) return ii(r,c);
        if(i!=n-1) { r++; nPow--; }
    }

    c++; nPow--;
    for(int i=0; i<n-2; i++){
        if(nPow==val) return ii(r,c);
        if(i!=n-3) { c++; nPow--; }
    }

    return findVal(nCor-1, n-2, val);
}

int findRing(long long n, long long val) {
    long long tVal=(long long)n*n;
    //cout<<"X"<<tVal<<endl;

    while(tVal>val) {
        n=n-2;
        tVal=n*n;
    }
    if(tVal==val) return n;
    return n+2;
}

int main() {
    int n,ringN;
    long long val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n>>val;
    while(n!=0) {
        ringN=findRing(n,val);
        ii res=findVal(ringN,ringN,val);
        cout<<"Line = "<<(n-ringN)/2+res.first<<", column = "<<(n-ringN)/2+res.second<<"."<<endl;
        cin>>n>>val;
    }
}
