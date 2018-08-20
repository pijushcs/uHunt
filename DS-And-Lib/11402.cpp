#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define lft(id) (id<<1)
#define rgh(id) ((id<<1)+1)

int st[1024002<<2];
char A[1024002], lz[1024002<<2];
char btx[1024002];

class SegTree {
public:

    char flipNow(char c) {
        if(c=='E') return 'F';
        if(c=='F') return 'E';

        if(c=='X') return 'I';
        return 'X';
    }

    int build(int l, int r, int id) {
        lz[id]='X';
        if(l==r) {
            st[id]=(A[l]=='1')?1:0;
            return st[id];
        }

        int lx=build(l, (l+r)/2, lft(id));
        int rx=build((l+r)/2+1, r, rgh(id));

        st[id]=lx+rx;
        return st[id];
    }

    int change(int i, int j, int l, int r, int id, int op) {
        if(lz[id]!='X') {
            char opx=lz[id];

            if(opx=='E') st[id]=0;
            else if(opx=='F') st[id]=(r-l)+1;
            else st[id]=((r-l)+1)-st[id];

            lz[id]='X';

            if(l!=r) {
                if(opx=='F' || opx=='E') lz[lft(id)]=lz[rgh(id)]=opx;
                else {
                    lz[lft(id)]=flipNow(lz[lft(id)]);
                    lz[rgh(id)]=flipNow(lz[rgh(id)]);
                }
            }
        }

        if(j<l || i>r) return st[id];

        if(l>=i && r<=j) {
            if(op=='F') st[id]=(r-l)+1;
            else if(op=='E') st[id]=0;
            else st[id]=((r-l)+1)-st[id];

            if(l!=r) {
                if(op=='F' || op=='E') lz[lft(id)]=lz[rgh(id)]=op;
                else {
                    lz[lft(id)]=flipNow(lz[lft(id)]);
                    lz[rgh(id)]=flipNow(lz[rgh(id)]);
                }
            }

            return st[id];
        }

        int lx=change(i,j,l,(l+r)/2,lft(id),op);
        int rx=change(i,j,(l+r)/2+1,r,rgh(id),op);

        st[id]=lx+rx;
        return st[id];
    }

    int rfq(int i, int j, int l, int r, int id) {
        if(j<l || i>r) return -1;

        if(lz[id]!='X') {
            char opx=lz[id];
            if(opx=='E') st[id]=0;
            else if(opx=='F') st[id]=(r-l)+1;
            else st[id]=((r-l)+1)-st[id];

            lz[id]='X';

            if(l!=r) {
                if(opx=='F' || opx=='E') lz[lft(id)]=lz[rgh(id)]=opx;
                else {
                    lz[lft(id)]=flipNow(lz[lft(id)]);
                    lz[rgh(id)]=flipNow(lz[rgh(id)]);
                }
            }
        }

        if(l>=i && r<=j) return st[id];

        int lx=rfq(i,j,l,(l+r)/2,lft(id));
        int rx=rfq(i,j,(l+r)/2+1,r,rgh(id));

        if(lx==-1) return rx;
        if(rx==-1) return lx;
        return (lx+rx);
    }
};

int main() {
    int t,n,m,x,y;
    char op;

    SegTree stx;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        scanf("%d", &m);
        int nstA=0;
        while(m--) {
            scanf("%d", &n);
            scanf("%s", &btx);
            for(int nx=1; nx<=n; nx++) {
                for(int nj=0; nj<strlen(btx); nj++)
                    A[nstA++]=btx[nj];
            }
        }
        A[nstA]='\0';

        //st=(int*)malloc(nstA*3*sizeof(int));
        stx.build(0, nstA-1, 1);
        scanf("%d\n", &n);
        printf("Case %d:\n", i);
        int k=1;
        for(int j=1; j<=n; j++) {
            scanf("%c %d %d\n", &op, &x, &y);
            if(op!='S') stx.change(x,y,0,nstA-1,1,op);
            else printf("Q%d: %d\n", k++, stx.rfq(x,y,0,nstA-1,1));
        }
    }
}
