#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> vnum, vmax, vseq, vmax_id;
long long maxNow=0;

//nlogn LIS
int maxSeqFast() {
    int pos, imax;
    vector<long long>::iterator ipos;

    vseq.assign(vnum.size(), 0);    // parent sequence
    vmax.assign(vnum.size(), 0);    // current lis seq
    vmax_id.assign(vnum.size(), 0); // index corresponding to vnum position

    for(int i=0; i<vnum.size(); i++) {
        ipos=lower_bound(vmax.begin(), vmax.begin()+maxNow, vnum[i]);
        pos=ipos-vmax.begin();

        vmax[pos]=vnum[i];
        vmax_id[pos]=i;

        vseq[i]=pos?vmax_id[pos-1]:i;

        if(pos+1>maxNow) {
            imax=i;
            maxNow=pos+1;
        }
    }

    return imax;
}

int maxSeq() {
    long long cmax;
    int n=vnum.size(), imax;

    vmax.assign(n, 1); vseq.clear();

    for(int i=0; i<n; i++) {
        cmax=1;
        vseq.push_back(i);
        for(int j=0; j<i; j++) {
            if(vnum[j]<vnum[i] && cmax<=(1+vmax[j])) {
                cmax=1+vmax[j];
                vseq[i]=j;
            }
        }
        vmax[i]=cmax;

        if(cmax>=maxNow) imax=i;
        maxNow=max(maxNow, cmax);
    }

    return imax;
}

// Recursive print
void rprint(int pos) {
    if(vseq[pos]==pos) {
        cout<<vnum[pos]<<endl;
        return;
    }
    rprint(vseq[pos]);
    cout<<vnum[pos]<<endl;
}

int main() {
    long long val;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>val))
        vnum.push_back(val);

    int imax=maxSeqFast();

    cout<<maxNow<<endl;
    cout<<"-"<<endl;

    rprint(imax);
}
