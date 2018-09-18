#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
    int n,m, ncase=1, inp,k;
    vector<int> vinp;

    freopen("testCase.txt", "r", stdin);

    cin>>n;
    while(n) {
        vinp.clear();

        for(int i=0; i<n; i++) {
            cin>>inp;
            vinp.push_back(inp);
        }
        sort(vinp.begin(), vinp.end());
        cout<<"Case "<<ncase++<<":"<<endl;

        cin>>m;

        while(m--) {
            cin>>k;

            int l=0, r=vinp.size()-1;
            int csum=vinp[l]+vinp[r];

            while(l<r) {
                if(abs((vinp[l]+vinp[r])-k) < abs(csum-k)) csum=vinp[l]+vinp[r];

                if(vinp[l]+vinp[r]<k) l++;
                else r--;
            }

            cout<<"Closest sum to "<<k<<" is "<<csum<<"."<<endl;
        }

        cin>>n;
        /**********************************************************************
        * Wrong-Assumption: Sum of (two numbers closest to k)                   *
        * while(m--) {                                                        *
        *    cin>>k;                                                          *
        *                                                                     *
        *    int dfirst=vinp[0], dsecond=vinp[1];                             *
        *    if (abs(k-dfirst)<abs(k-dsecond)) swap(dfirst,dsecond);          *
        *                                                                     *
        *    for(int i=2; i<vinp.size(); i++) {                               *
        *        if(abs(vinp[i]-k)<abs(k-dfirst)) dfirst=vinp[i];             *
        *        else if(abs(vinp[i]-k)<abs(k-dsecond)) dsecond=vinp[i];      *
        *                                                                     *
        *        if (abs(k-dfirst)<abs(k-dsecond)) swap(dfirst,dsecond);      *
        *        cout<<k<<" "<<dfirst<<" "<<dsecond<<" "<<vinp[i]<<endl;      *
        *    }                                                                *
        *                                                                     *
        *    cout<<"Closest sum to "<<k<<" is "<<dfirst+dsecond<<"."<<endl;   *
        * }                                                                   *
        ***********************************************************************/
    }
}
