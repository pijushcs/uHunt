#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int coef[30];

long long findVal(int n, int d, int k) {
    long long cPos=1, curD=d, an=1, res=0;

    while(cPos<=k) {
        curD=an*d;
        cPos+=curD;

        an++;
    }

    for(int i=0; i<=n; i++)
        res+=(coef[i]*pow(an-1,i));

    return res;
}

int main() {
    int t,n,d,k;

    freopen("testCase.txt", "r", stdin);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0; i<=n; i++)
            cin>>coef[i];

        cin>>d>>k;
        cout<<findVal(n,d,k)<<endl;
    }
}
