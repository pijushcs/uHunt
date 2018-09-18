#include<iostream>
#include<vector>
using namespace std;

long long s,d;

long long findSurplus(int p, vector<long long> &csum, long long tsum) {
    if(p>12)
        return tsum;

    long long sres=-100000000, dres=-100000000;

    if(p>=5) {
        if(csum[p-1]-csum[p-5]+s<0) {
            csum[p]=csum[p-1]+s;
            sres=findSurplus(p+1,csum, tsum+s);
        }

        if(csum[p-1]-csum[p-5]-d<0) {
            csum[p]=csum[p-1]-d;
            dres=findSurplus(p+1,csum, tsum-d);
        }

        return max(sres, dres);
    }

    csum[p]=csum[p-1]+s;
    sres=findSurplus(p+1, csum, tsum+s);

    csum[p]=csum[p-1]-d;
    dres=findSurplus(p+1, csum, tsum-d);

    return max(sres, dres);
}

int main() {
    vector<long long> csum;

    while((cin>>s)) {
        cin>>d;
        csum.assign(13,0);
        long long res=findSurplus(1,csum,0);

        if(res<0) cout<<"Deficit"<<endl;
        else cout<<res<<endl;
    }
}
