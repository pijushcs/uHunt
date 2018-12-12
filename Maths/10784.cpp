#include<iostream>
#include<cmath>
using namespace std;

long long findSol(long long k) {
    long double dx=sqrt(3.0*3.0+4.0*2.0*k);
    return ceil((3.0 + dx)/2.0);
}

int main() {
    long long k, tcase=1;

    cin>>k;
    while(k) {
        cout<<"Case "<<tcase++<<": "<<findSol(k)<<endl;
        cin>>k;
    }
}


