#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pjump(vector<long long> &hung, long long k) {
    long long phung=0;
    for(int i=0; i<hung.size(); i++) {
        if(hung[i]-phung==k) k--;
        else if(hung[i]-phung>k) return -1;

        phung=hung[i];
    }

    return k;
}

long long findSteps(vector<long long> &hung) {
    long long lo=hung[0], hi=hung[hung.size()-1];
    long long minNow=100000000000000, res, mid;

    while(lo<=hi) {
        mid=(hi+lo)/2;

        res=pjump(hung, mid);
        if(res==0) return mid;

        if(res>0) minNow=min(minNow, mid);

        // Note: lo and hi are !set to mid since the range of mid is not continuous in [lo, hi].
        // For example, let [12,13] be the range and let 13 be the correct ans. mid will never reach
        // 13 as mid is an integer and will always be 12, i.e (int)(13+12)/2.
        // So, if mid is not the answer, remove mid and check the other part [mid+1, hi] or [lo, mid-1]
        // But, in case of continuous mid, i.e mid is double.. its better to set lo, hi as mid.
        if(res<0) lo=mid+1;
        else hi=mid-1;
    }

    return minNow;
}

int main() {
    int t, n, tcase=1;
    long long val;
    vector<long long> hung;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut-2.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n;

        hung.clear();
        for(int i=0; i<n; i++) {
            cin>>val; hung.push_back(val);
        }

        cout<<"Case "<<tcase++<<": "<<findSteps(hung)<<endl;
    }
}
