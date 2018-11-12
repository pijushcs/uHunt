#include<iostream>
#include<cmath>
using namespace std;

long long fib[15001], rep[]={60, 300, 1500, 15000};

long long computeFib(int a, int b, int k, int m) {
    fib[0]=a, fib[1]=b;

    for(int i=2; i<=k; i++)
        fib[i]=(fib[i-1]+fib[i-2])%10000;

    double powm=pow(10, m);
    return fib[k]%(int)powm;
}

int main() {
    int t, m, a, b;
    long long n;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>a>>b>>n>>m;

        int k=n%rep[m-1];
        cout<<computeFib(a,b,k,m)<<endl;
    }
}
