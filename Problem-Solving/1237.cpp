#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstdio>
using namespace std;

typedef pair<int,int> ii;

map<ii, string> mCar;

string findCar(int n) {
    int nRes=0;
    string nString;

    for(map<ii, string>::iterator it=mCar.begin(); it!=mCar.end(); it++) {
        //cout<<(*it).first.first<<" "<<(*it).first.second<<" "<<(*it).second<<endl;
        if(n>=(*it).first.first && n<=(*it).first.second) {
            nRes++;
            nString=(*it).second;
        }
        if(nRes>1) return "UNDETERMINED";
    }

    if(nRes) return nString;
    return "UNDETERMINED";
}

int main() {
    int t,m,n,a,b;
    string str;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        mCar.clear();

        cin>>m;
        while(m--) {
            cin>>str>>a>>b;
            mCar[ii(a,b)]=str;
        }

        cin>>n;
        while(n--) {
            cin>>a;
            cout<<findCar(a)<<endl;
        }

        if(t) cout<<endl;
    }
}
