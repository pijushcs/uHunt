#include<iostream>
#include<cstring>
using namespace std;

long long dP[30][30];

long long nbracket(int l, int r) {
    long long res=0;

    if(r-l+1<=2) return 1;

    if(dP[l][r]!=-1)
        return dP[l][r];

    for(int i=l+1; i<=r; i++) {
        res+=nbracket(l,i-1)*nbracket(i,r);
    }

    dP[l][r]=res;
    return res;
}

int main() {
    int n;

    for(int i=0; i<30; i++)
        memset(dP[i], -1, 30*sizeof(long long));

    while((cin>>n))
        cout<<nbracket(1, n)<<endl;
}
