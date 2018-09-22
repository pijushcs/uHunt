#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    long long n, bpay, val, cmin;
    pair<long long, long long> res;
    vector<long long> vbooks;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>n)) {
        vbooks.clear();
        cmin=10000000000;

        for(int i=0; i<n; i++) {
            cin>>val;
            vbooks.push_back(val);
        }

        sort(vbooks.begin(), vbooks.end());

        cin>>bpay;
        for(int i=0; i<vbooks.size()-1; i++) {
            long long fbook=vbooks[i];
            if(binary_search(vbooks.begin()+(i+1), vbooks.end(), bpay-fbook)) {
                long long ebook=bpay-fbook;

                if(ebook-fbook < cmin) {
                    res.first=fbook;
                    res.second=ebook;
                    cmin=ebook-fbook;
                }
            }
        }

        cout<<"Peter should buy books whose prices are "<<res.first<<" and "<<res.second<<"."<<endl<<endl;
    }
}
