#include<iostream>
using namespace std;

long long n, a, b;

long long f(long long x) {
    return (((a%n*x%n)%n*x%n)%n+b%n)%n;
}

long long floydCycle(long long l) {
    long long torx=f(l), harex=f(f(l));
    while(torx!=harex) { torx=f(torx); harex=f(f(harex)); }

    harex=l;
    while(torx!=harex) { torx=f(torx); harex=f(harex); }

    harex=f(torx); long long ncycle=1;
    while(torx!=harex) { harex=f(harex); ncycle++; }

    return n-ncycle;
}

int main() {
    long long x;

    cin>>n;
    while(n!=0) {
        cin>>a>>b;
        cout<<floydCycle(0)<<endl;

        cin>>n;
    }
}
