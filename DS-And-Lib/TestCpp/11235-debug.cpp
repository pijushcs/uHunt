#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define lft(p) (p<<1)
#define rgh(p) ((p<<1)+1)

typedef vector<int> vi;
typedef pair<int,int> ii;

class SegTree {
public:
    vi p, A;
    map<int, ii> mapPt;

    int build(int l, int r, int id) {
        if(l==r) {
            p[id]=1;
            return 1;
        }

        int mid=(l+r)/2;

        int lx=build(l, (l+r)/2, lft(id));
        int rx=build((l+r)/2+1, r, rgh(id));

        int lpx=0, rpx=0;
        if(A[mid]==A[(l+r)/2+1]) {
            if(mapPt[A[mid]].first<l) lpx=l;
            else lpx=mapPt[A[mid]].first;

            if(mapPt[A[mid]].second>r) rpx=r;
            else rpx=mapPt[A[mid]].second;
        }

        p[id]=max(rpx-lpx+1, max(lx, rx));
        return p[id];
    }

    int rfq(int i, int j, int l, int r, int id) {
        cout<<l<<" "<<r<<endl;
        if(l>=i && r<=j) { cout<<"A "<<l<<" "<<" "<<r<<": "<<p[id]<<endl; return p[id]; }
        if(i>r || j<l) { cout<<l<<" "<<" "<<r<<": "<<-1<<endl; return -1; }

        int lx=rfq(i,j, l, (l+r)/2, lft(id));
        int rx=rfq(i,j, (l+r)/2+1, r, rgh(id));

        int mid=(l+r)/2;

        int lpx=0, rpx=0;
        if(A[mid]==A[(l+r)/2+1]) {

            if(mapPt[A[mid]].first<i) lpx=i;
            else lpx=mapPt[A[mid]].first;

            if(mapPt[A[mid]].second>j) rpx=j;
            else rpx=mapPt[A[mid]].second;

            cout<<"C "<<l<<" "<<" "<<r<<": "<<lpx<<" "<<rpx<<" "<<mapPt[A[mid]].first<<" "<<mapPt[A[mid]].second<<endl;
        }

        cout<<"B "<<l<<" "<<" "<<r<<": "<<rpx<<" "<<lpx<<" "<<lx<<" "<<rx<<endl;
        return max(rpx-lpx+1, max(lx, rx));
    }

    void init(int n) {
        mapPt.clear();
        p.assign(n*4+1, 0);
        A.assign(n+10, 0);
    }
};

int main() {
    int n, q, x, l, r, prev=-100001;
    SegTree segx;

    cin>>n;
    while(n!=0) {
        cin>>q;
        segx.init(n);
        for(int i=1; i<=n; i++) {
            cin>>x; segx.A[i]=x;
            if(prev!=x) {
                segx.mapPt[x].first=i;
                segx.mapPt[x].second=i;
            }
            else if(prev==x) segx.mapPt[x].second=i;
            prev=x;
        }

        segx.build(1, n, 1);
        for(int i=1; i<4*n; i++) cout<<segx.p[i]<<" ";
        cout<<endl;

        for(int i=1; i<=q; i++) {
            cin>>l>>r;
            cout<<segx.rfq(l,r,1,n,1)<<endl;
        }

        cin>>n;
    }
}
