#include<iostream>
using namespace std;

long long f(long long l) {
    long long lprod=l*l;
    return (lprod/100)%10000;
}

long long floydCycle(long long l) {
    long long torx=f(l), harex=f(f(l));
    while(torx!=harex) { torx=f(torx); harex=f(f(harex)); }

    harex=l; long long nseq=1;
    while(torx!=harex) { torx=f(torx); harex=f(harex); nseq++; }

    harex=f(torx); long long ncycle=1;
    while(torx!=harex) { harex=f(harex); ncycle++; }

    return ncycle+nseq-1; // starting seq is counted twice
}

int main() {
    long long l;

    cin>>l;
    while(l) {
        cout<<floydCycle(l)<<endl;
        cin>>l;
    }
}
