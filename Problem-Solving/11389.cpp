#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n,d,r,val;
    long long tsum;
    vector<int> vmon, veve;

    cin>>n>>d>>r;
    while(n!=0) {
        vmon.clear();
        for(int i=0; i<n; i++) {
            cin>>val; vmon.push_back(val);
        }
        sort(vmon.begin(), vmon.end());

        veve.clear();
        for(int i=0; i<n; i++) {
            cin>>val; veve.push_back(val);
        }
        sort(veve.begin(), veve.end());

        tsum=0;
        for(int i=0; i<n; i++) {
            if(vmon[i]+veve[n-i-1]>d)
                tsum+=((vmon[i]+veve[n-i-1]-d))*r;
        }

        cout<<tsum<<endl;
        cin>>n>>d>>r;
    }
}
