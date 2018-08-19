#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class UnionFind {
public:
    map<string, long long> crank, csize;
    map<string, string> p;

    void initStr(string a) {
        p[a]=a;
        csize[a]=1;
    }

    bool isSameSet(string a, string b) {
        if(p.find(a)==p.end()) initStr(a);
        if(p.find(b)==p.end()) initStr(b);

        if (findSet(a).compare(findSet(b))) return false;
        return true;
    }

    string findSet(string a) {
        if(p[a].compare(a) == false) return a;
        return p[a]=findSet(p[a]);
    }

    int unionSet(string a, string b) {
        if(isSameSet(a,b)) return csize[findSet(a)];
        string x=findSet(a), y=findSet(b);

        if(crank[x]>crank[y]) {
            p[y]=x;

            csize[x]=csize[y]+csize[x];
            return csize[x];
        }
        else {
            p[x]=y;
            if(crank[x]==crank[y]) crank[y]++;

            csize[y]=csize[x]+csize[y];
            return csize[y];
        }
    }

    void init() {
        p.clear(); csize.clear();
        crank.clear();
    }
};

int main() {
    int t, n;
    string a,b;
    UnionFind netx;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n;

        netx.init();
        while(n--) {
            cin>>a>>b;
            cout<<netx.unionSet(a,b)<<endl;
        }
    }
}
