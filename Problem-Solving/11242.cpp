#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    int f, r, cx;
    vector<double> vang;
    vector<int> vr, vf;

    cin>>f;
    while(f!=0) {
        cin>>r;
        vang.clear(); vr.clear(); vf.clear();

        for(int i=0; i<f; i++) {
            cin>>cx; vf.push_back(cx);
        }

        for(int i=0; i<r; i++) {
            cin>>cx; vr.push_back(cx);
        }

        for(int i=0; i<r; i++)
            for(int j=0; j<f; j++)
                vang.push_back((double)vr[i]/(double)vf[j]);

        sort(vang.begin(), vang.end());

        double maxNow=0.0;
        for(int i=1; i<vang.size(); i++)
            maxNow=max(maxNow, vang[i]/vang[i-1]);

        printf("%0.2f\n",maxNow);

        cin>>f;
    }
}
