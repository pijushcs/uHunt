#include<iostream>
#include<bitset>
#include<algorithm>
#include<map>
using namespace std;

map<long long, long long> snowMap;

int main() {
    long long n, id, t, res, curSize, lPos;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        snowMap.clear();
        res=0;
        curSize=1;
        lPos=1;

        cin>>n;
        while(n--) {
            cin>>id;
            if(snowMap[id]!=0) {
                if(lPos<snowMap[id]+1)
                    lPos=snowMap[id]+1;
                snowMap[id]=curSize++;
            }
            else {
                snowMap[id]=curSize++;
            }
            res=max(snowMap[id]-lPos+1,res);
        }
        cout<<res<<endl;
    }
}
