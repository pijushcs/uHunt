#include<iostream>
using namespace std;

long long z, i, m;

long long f(long long l) {
    return (l*z+i)%m;
}

long long floydCycle(long long l) {
    long long torx=f(l), harex=f(f(l));
    while(torx!=harex) { torx=f(torx); harex=f(f(harex)); }

    harex=l;
    while(torx!=harex) { torx=f(torx); harex=f(harex); }

    long long ncycle=1; harex=f(harex);
    while(torx!=harex) { harex=f(harex); ncycle++; }

    return ncycle;
}

int main() {
    long long l, tcase=1;

    cin>>z>>i>>m>>l;
    while(l!=0 || z!=0 || i!=0 || m!=0) {
        cout<<"Case "<<tcase++<<": "<<floydCycle(l)<<endl;
        cin>>z>>i>>m>>l;
    }
}
