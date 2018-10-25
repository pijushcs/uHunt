#include<iostream>
using namespace std;

long long findVal(long long n, long long l, long long u) {
    long long m=0L,t;

    for(int i=32; i>=0; i--) {
        if((n&(1L<<i))) {
            t=m|((1L<<i)-1);
            if(t<l) m=m|(1L<<i);
        }
        else if((m|(1L<<i))<=u)
                m=(m|(1L<<i));
    }

    return m;
}

int main() {
    long long n,l,u;

    while((cin>>n)) {
        cin>>l>>u;

        cout<<findVal(n,l,u)<<endl;
    }
}
