#include<iostream>
#include<string>
#include<bitset>
#include<map>
using namespace std;

int main() {
    int n, ncx, maxNow=0, res;
    bitset<510> mBits;
    map<string, int> cMap;
    string bitStr;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n;
    while(n!=0){
        cMap.clear();
        maxNow=0;

        for(int i=0; i<n; i++) {
            mBits.reset();

            for(int nC=0; nC<5; nC++) {
                cin>>ncx;
                mBits.set(ncx);
            }

            bitStr=mBits.to_string();
            cMap[bitStr]=cMap[bitStr]+1;

            if(cMap[bitStr]>maxNow) maxNow=cMap[bitStr];
        }

        res=0;
        for(map<string, int>::iterator it=cMap.begin();  it!=cMap.end(); it++) {
            if(it->second == maxNow) res+=maxNow;
        }

        cout<<res<<endl;
        cin>>n;
    }
}
