#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

long long dP[1000];

long long findNPossible(int n) {
    long long res=0;

    if(n<0) return 0;
    if(n==0) return 1;

    if(dP[n]!=-1) return dP[n];

    res=4*findNPossible(n-2)+findNPossible(n-1)+2*findNPossible(n-3);
    dP[n]=res;

    return res;
}

int main() {
    int t, n;

    cin>>t;
    while(t--) {
        cin>>n;
        memset(dP, -1, (n+1)*sizeof(long long));

        cout<<findNPossible(n)<<endl;
    }
}
