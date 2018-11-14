#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef pair<int, string> is;
map<is, long long> dP;

int n;
long long nWays(int p, string smask) {
    long long res=0;

    if(p==n) return 1;
    if(smask[p]=='1')
        return nWays(p+1, smask);

    if(dP.find(is(p,smask))!=dP.end())
        return dP[is(p,smask)];

    for(int i=p+1; i<n; i++) {
        if(smask[i]=='0') {
            smask[i]='1';
            res+=nWays(p+1, smask);
            smask[i]='0';
        }
        else break;
    }

    dP[is(p,smask)]=res;
    return res;
}

int main() {
    bool nflag=false;
    while((cin>>n)) {
        n=2*n; dP.clear();
        string smask(30,'0');

        if(nflag) cout<<endl;
        cout<<nWays(0, smask)<<endl;
        nflag=true;
    }
}
