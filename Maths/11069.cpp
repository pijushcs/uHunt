#include<iostream>
#include<cstring>
using namespace std;

long long dP[100];
long long nsubset(int n) {
    long long res=0;

    if(n<=0) return 0;
    if(n==1 || n==2) return 1;
    if(dP[n]!=-1) return dP[n];

    if(n-2>0) res+=nsubset(n-2);
    if(n-3>0) res+=nsubset(n-3);

    dP[n]=res;
    return res;
}

int main() {
    int n;

    memset(dP, -1, 100*sizeof(long long));
    while(cin>>n) {
        cout<<nsubset(n)+nsubset(n-1)<<endl;
    }
}
