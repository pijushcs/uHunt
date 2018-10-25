#include<iostream>
#include<vector>
#include<string>
using namespace std;

long long d;
vector<long long> vstone;
vector<bool> bskey, vskey;
vector<int> dP;

long long findPathBT(long long curd, int pos) {
    long long cstep=-1, mstep=1000000000000;

    if(curd==d) {
        for(int i=vstone.size()-1; i>=0; i--)
            if(bskey[i]==false) {
                cstep=max(cstep, curd-vstone[i]);
                curd=vstone[i];
            }

        return max(cstep, curd-0);
    }

    for(int i=pos; i<vstone.size(); i++) {
        if(vskey[i]==true) {
            bskey[i]=true;
            mstep=min(mstep, max((vstone[i]-curd),findPathBT(vstone[i], i+1)));
            bskey[i]=false;
        }
        else {
            mstep=min(mstep, max((vstone[i]-curd),findPathBT(vstone[i], i+1)));
            break;
        }
    }

    mstep=min(mstep, max((d-curd),findPathBT(d,-1)));
    return mstep;
}

long long findPath(long long curd, long long startd, int spos, int pos) {
    long long mstep=100000000000, cstep=-1;
    int cpos;

    if(curd==d) {
        for(int i=vstone.size()-1; i>spos; i--) {
            if(bskey[i]==false) {
                cstep=max(cstep, (curd-vstone[i]));
                curd=vstone[i];
            }
        }

        return max(cstep, (curd-startd));
    }

    if(pos>=0 && pos<vstone.size() && dP[pos]!=-1) {
        cpos=dP[pos];
        if(cpos<vstone.size()) {
            if(vskey[cpos]) bskey[cpos]=true;
            return max((vstone[cpos]-curd), findPath(vstone[cpos], startd, spos, cpos));
            if(vskey[cpos]) bskey[cpos]=true;
        }
        else
            return max((d-curd), findPath(d, startd, spos, -1));
    }

    for(int i=pos+1; i<vstone.size(); i++) {
        if(vskey[i]) bskey[i]=true;
        cstep=findPath(vstone[i], startd, spos, i);
        if(vskey[i]) bskey[i]=false;

        if(mstep>max(cstep, (vstone[i]-curd))) {
            mstep=max(cstep, (vstone[i]-curd));
            dP[pos]=i;
        }
    }

    cstep=findPath(d, startd, spos, -1);
    if(mstep>max(cstep, (d-curd))) {
        mstep=max(cstep, (d-curd));
        if(pos<vstone.size()) dP[pos]=vstone.size();
    }

    return mstep;
}

long long findPathDP() {
    long long mstep;
    for(int i=vstone.size()-1; i>=0; i--)
        mstep=findPath(vstone[i], vstone[i], i, i);

    return mstep;
}

int main() {
    int t,n, tcase=1;
    long long m;

    char c, tempc;
    string tstr;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n>>d;
        getline(cin, tstr);

        vskey.assign(n+1, false);
        bskey.assign(n+1, false);
        dP.assign(n+1, -1);
        vstone.clear(); vstone.push_back(0);

        for(int i=1; i<=n; i++) {
            cin>>c>>tempc>>m;
            vstone.push_back(m);
            if(c=='S') vskey[i]=true;
        }

        cout<<"Case "<<tcase++<<": "<<findPathDP()<<endl;
    }
}
