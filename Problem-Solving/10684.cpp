#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long n, val, maxNow, csum;

    cin>>n;
    while(n!=0) {
        csum=0, maxNow=-10000000;
        for(int i=0; i<n; i++) {
            cin>>val;
            csum+=val;

            maxNow=max(maxNow, csum);
            if(csum<0) csum=0;
        }

        if(maxNow<=0) cout<<"Losing streak."<<endl;
        else cout<<"The maximum winning streak is "<<maxNow<<"."<<endl;

        cin>>n;
    }
}
