#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind {
public:
    vi p, crank;

    bool isSameSet(int u, int v) {
        return findSet(u)==findSet(v);
    }

    int findSet(int u) {
        if(p[u]==u) return u;
        return (p[u]=findSet(p[u]));
    }

    void unionSet(int u, int v) {
        if(isSameSet(u,v)) return;
        int x=findSet(u), y=findSet(v);

        if(crank[x]>crank[y]) p[y]=x;
        else {
            p[x]=y;
            if(crank[x]==crank[y]) crank[y]++;
        }

    }

    void init(int n) {
        crank.assign(n+1, 0);
        p.assign(n+1, 0);

        for(int i=1; i<=n; i++) p[i]=i;
    }
};

int main() {
    UnionFind netx;
    int t,u,v,ns,nc,n;
    char opx;
    string str;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>n; getline(cin, str);
        netx.init(n);
        ns=0; nc=0;

        getline(cin, str);
        while(str.compare("")) {
            sscanf(str.c_str(), "%c %d %d", &opx, &u, &v);
            if(opx=='c') netx.unionSet(u,v);
            if(opx=='q') {
                if(netx.isSameSet(u,v)) ns++;
                else nc++;
            }
            getline(cin, str);
        }

        cout<<ns<<","<<nc<<endl;
        if(t) cout<<endl;
    }
}
