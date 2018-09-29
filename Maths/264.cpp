#include<iostream>
#include<vector>
using namespace std;

typedef pair<long long, long long> ll;

ll findTerm(long long n) {
    long long k=1, r=1, c=1;
    bool isMoveUp=false;

    while(k<n) {
        k++;
        if(r==1 && c%2) {
            c++;
            isMoveUp=false;
        }
        else if(c==1 && r%2==0) {
            r++;
            isMoveUp=true;
        }
        else {
            if(isMoveUp) {r--; c++;}
            else {r++; c--;}
        }
    }

    return ll(r,c);
}

int main() {
    long long n;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut-2.txt", "w", stdout);

    while((cin>>n)) {
        ll res=findTerm(n);
        cout<<"TERM "<<n<<" IS "<<res.first<<"/"<<res.second<<endl;
    }
}
