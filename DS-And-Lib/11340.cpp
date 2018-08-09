#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int t,n;
    long pVal,pDol,pSum,pCent;
    long pMap[10000];
    string str;
    char pChar;

    freopen("testCase.txt", "r", stdin);
    //freopen("testOut.txt", "w", stdout);

    cin>>t;

    while(t--) {
        cin>>n;
        for(int i=0; i<10000; i++) pMap[i]=0;
        for(int i=0; i<n; i++) {
            cin>>pChar>>pVal;
            pMap[128+(int)pChar]=pVal;
        }

        cin>>n;
        getline(cin, str);
        pSum=0;

        for(int i=0; i<n; i++) {
            getline(cin, str);
            for(int i=0; i<str.length(); i++)
                pSum+=pMap[128+(int)str[i]];
        }

        pDol=pSum/100;
        pCent=pSum%100;

        if(pCent<10) printf("%d.0%d$\n",pDol,pCent);
        else printf("%d.%2d$\n",pDol,pCent);
    }
}
