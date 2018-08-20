#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define lft(id) (id<<1)
#define rgh(id) ((id<<1)+1)

typedef pair<int,int> ii;
typedef vector<char> vc;

class SegTree {
public:
    vc st, A;

    char build(int l, int r, int id) {
        if(l==r) {
            st[id]=A[l];
            return st[id];
        }

        char lx=build(l, (l+r)/2, lft(id));
        char rx=build((l+r)/2+1, r, rgh(id));

        st[id]='+';
        if(lx=='0' || rx=='0') st[id]='0';
        else if(lx=='-' && rx=='-') st[id]='+';
        else if(lx=='-' || rx=='-') st[id]='-';

        return st[id];
    }

    char change(int pos, int l, int r, int id) {
        if(pos<l || pos>r) return st[id];

        if(l==r && l==pos) {
            st[id]=A[pos];
            return st[id];
        }

        char lx=change(pos, l, (l+r)/2, lft(id));
        char rx=change(pos, (l+r)/2+1, r, rgh(id));

        st[id]='+';
        if(lx=='0' || rx=='0') st[id]='0';
        else if(lx=='-' && rx=='-') st[id]='+';
        else if(lx=='-' || rx=='-') st[id]='-';

        return st[id];
    }

    char rpq(int i, int j, int l, int r, int id) {
        if(j<l || i>r) return '+';
        if(l>=i && r<=j) return st[id];

        char lx=rpq(i, j, l, (l+r)/2, lft(id));
        char rx=rpq(i, j, (l+r)/2+1, r, rgh(id));

        if(lx=='0' || rx=='0') return '0';
        else if(lx=='-' && rx=='-') return '+';
        else if(lx=='-' || rx=='-') return '-';

        return '+';
    }

    void init(int n) {
        st.assign(n*4+1, '+');
        A.assign(n+1, '+');
    }
};

int main() {
    int n, q, x, y;
    char op, cx;
    SegTree stx;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>n>>q)) {
        stx.init(n);
        for(int i=1; i<=n; i++) {
            cin>>x;
            stx.A[i]=(x>0)?'+':(x==0?'0':'-');
        }

        stx.build(1,n,1);

        for(int i=0; i<q; i++) {
            cin>>op>>x>>y;
            if(op=='C') {
                cx=(y>0)?'+':(y==0?'0':'-');
                if(cx!=stx.A[x]) {
                    stx.A[x]=cx;
                    stx.change(x,1,n,1);
                }
            }
            else cout<<stx.rpq(x,y,1,n,1);
        }

        cout<<endl;
    }
}
