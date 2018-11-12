#include<iostream>
#include<cstring>
#include<string>
using namespace std;

typedef pair<string, string> ss;
long long dP[51][51];
int n;

long long computeCoef(int n, int k) {
    if(n>=0 && k==0) return 1;
    if(n<=0 || k<0) return 0;

    if(dP[n][k]!=-1) return dP[n][k];

    long long res = computeCoef(n-1,k-1)+computeCoef(n-1,k);
    dP[n][k]=res;

    return res;
}

ss tokenizeStr(string &str) {
    ss spair;

    int apos, bpos;
    for(int i=1; i<str.length()-1; i++) {
        if(str[i]=='+') apos=i;
        if(str[i]==')') { bpos=i; break; }
    }

    spair.first=str.substr(1, apos-1); // length is (pos-1)-1 + 1
    spair.second=str.substr(apos+1, bpos-apos-1); // length is (bpos-1)-(apos+1) + 1

    string nstr="";
    for(int i=bpos+2; i<str.length(); i++) nstr+=str[i];
    n=stoi(nstr);

    return spair;
}

int main() {
    int t, nx, ny, tcase=1;
    string x,y, str;
    long long bcoef;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    for(int i=0; i<51; i++)
        memset(dP[i], -1, 51*sizeof(long long));

    cin>>t; getline(cin, str);
    while(t--) {
        getline(cin, str);

        ss spair=tokenizeStr(str);
        x=spair.first; y=spair.second;

        cout<<"Case "<<tcase++<<": ";
        for(int i=0; i<=n; i++) {
            ny=i; nx=n-i;

            if(i<=n-i) bcoef=computeCoef(n,i);
            else bcoef=computeCoef(n,n-i);

            if(i>0) cout<<"+";
            if(bcoef!=1) cout<<bcoef<<"*";

            if(nx!=0) cout<<x;
            if(nx>1) cout<<"^"<<nx;

            if(nx!=0 && ny!=0) cout<<"*";

            if(ny!=0) cout<<y;
            if(ny>1) cout<<"^"<<ny;
        }

        cout<<endl;
    }
}
