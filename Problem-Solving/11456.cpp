#include<iostream>
#include<map>
#include<queue>
using namespace std;

/********************************************************************
* amax[i]/dmax[i] denotes asc/desc seuence starting at i. We can    *
* can place the desc[i] seq before vtrain[i] and the asc[i] seq     *
* after vtrain[i]. Starting at i means, all k<i are ignored.        *
*                                                                   *
* Let i<k<t be the positions:                                       *
* if v[i]<v[k]<v[t], the asc seq v[i],v[k],v[t] is already in place *
* if v[i]>v[k]>v[t], the des seq v[t],v[k],v[i] can be easily done  *
********************************************************************/
int vtrain[2100], amax[2100], dmax[2100];

// Recursive Complete Search
int maxTrainSeq(int pos, int n, int l, int r) {
    int res=0, lmax=0, rmax=0;
    if(pos==n) return 0;

    if(l==-1)
        return max(maxTrainSeq(pos+1,n,l,r), 1+maxTrainSeq(pos+1, n, pos, pos));

    if(vtrain[l]>=vtrain[pos]) lmax=1+maxTrainSeq(pos+1, n, pos, r);
    if(vtrain[r]<=vtrain[pos]) rmax=1+maxTrainSeq(pos+1, n, l, pos);

    return max(max(lmax, rmax),maxTrainSeq(pos+1, n, l, r));
}

/*****************************************************************
* Note: We cannot have amex[i]/dmax[i] as asc/desc seq ending at *
* position i, since we cannot place the dmax[i] seq ending at i  *
* after vtrain[i] in this case as by the time we get to i, all   *
* positions k<i has to be either ignored or put in place. We can *
* only successfully place the amax[i] seq in this case.          *
*****************************************************************/

int maxTrainSequence(int n) {
    int maxNow=0;

    for(int i=n-1; i>=0; i--) {
        int amaxNow=1, dmaxNow=1;

        for(int j=n-1; j>i; j--) {
            if(vtrain[j]<vtrain[i]) amaxNow=max(amaxNow, 1+amax[j]);
            else if(vtrain[j]>vtrain[i]) dmaxNow=max(dmaxNow, 1+dmax[j]);
        }

        amax[i]=amaxNow; dmax[i]=dmaxNow;
        maxNow=max(maxNow, amax[i]+dmax[i]-1);
    }

    return maxNow;
}

int main() {
    int t, n;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n;

        for(int i=0; i<n; i++)
            cin>>vtrain[i];

        cout<<maxTrainSequence(n)<<endl;
    }
}
