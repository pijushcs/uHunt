#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

bitset<50> bset;
vector<int> vset, vprime;

void printSol(int n) {
    cout<<"1";
    for(int i=2; i<=n; i++)
        cout<<" "<<vset[i];
    cout<<endl;
}

bool isPrime(int n) {
    if(vprime[n]!=-1)
        return (vprime[n]==0)?false:true;

    for(int i=2; i<=n/2; i++) {
        if((n%i)==0) {
            vprime[n]=0;
            return false;
        }
    }

    vprime[n]=1;
    return true;
}

void printCircle(int p, int n) {
    //cout<<p<<" "<<vset[p-1]<<endl;
    if(p>n) {
        if(isPrime(vset[n]+1))
            printSol(n);
        return;
    }

    if(p==1) {
        vset[p]=1; bset.set(1);
        printCircle(p+1, n);
        return;
    }

    for(int i=2; i<=n; i++) {
        if(bset.test(i)==false && isPrime(vset[p-1]+i)) {
            vset[p]=i; bset.set(i);
            printCircle(p+1, n);
            bset.reset(i);
        }
    }
}

int main() {
    int n, tcase=1;

    vprime.assign(100, -1);

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>n)) {
        if(tcase>1) cout<<endl;
        cout<<"Case "<<tcase++<<":"<<endl;

        vset.assign(n+1,0); bset.reset();
        printCircle(1, n);
    }
}
