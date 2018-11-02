#include<iostream>
#include<cstring>
using namespace std;

int hdP[50][50][50][50], gdP[50][50][50][50];

int findCake(int p, int tr, int tc, int br, int bc, int r, int c) {
    int res;

    if(p==0) {
        if(tr==r && tc==c && br==r && bc==c) return 0; // Hansel lost

        if(hdP[tr][tc][br][bc]!=-1)
            return hdP[tr][tc][br][bc];

        for(int i=tr+1; i<=br; i++) {
            if(r>=i) res=findCake(1, i, tc, br, bc, r, c);
            else res=findCake(1, tr, tc, i-1, bc, r, c);

            // Hansel tries to play optimal cut
            if(res==1) {
                hdP[tr][tc][br][bc]=res;
                return res;
            }
        }

        for(int i=tc+1; i<=bc; i++) {
            if(c>=i) res=findCake(1, tr, i, br, bc, r, c);
            else res=findCake(1, tr, tc, br, i-1, r, c);

            if(res==1) {
                hdP[tr][tc][br][bc]=res;
                return res;
            }
        }

        hdP[tr][tc][br][bc]=0;
        return 0;
    }
    else {
        if(tr==r && tc==c && br==r && bc==c) return 1; // Gretel Lost

        if(gdP[tr][tc][br][bc]!=-1)
            return gdP[tr][tc][br][bc];

        for(int i=tr+1; i<=br; i++) {
            if(r>=i) res=findCake(0, i, tc, br, bc, r, c);
            else res=findCake(0, tr, tc, i-1, bc, r, c);

            if(res==0) {
                gdP[tr][tc][br][bc]=res;
                return res;
            }
        }

        for(int i=tc+1; i<=bc; i++) {
            if(c>=i) res=findCake(0, tr, i, br, bc, r, c);
            else res=findCake(0, tr, tc, br, i-1, r, c);

            if(res==0) {
                gdP[tr][tc][br][bc]=res;
                return res;
            }
        }

        gdP[tr][tc][br][bc]=1;
        return 1;
    }

    return -1;
}

int main() {
    int t, r, c, nr, nc;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>nr>>nc>>r>>c;
        for(int i=0; i<nr; i++)
            for(int j=0; j<nc; j++)
                for(int k=0; k<nr; k++) {
                    memset(hdP[i][j][k], -1, nc*sizeof(int));
                    memset(gdP[i][j][k], -1, nc*sizeof(int));
                }

        if(findCake(0, 0, 0, nr-1, nc-1, r, c))
            cout<<"Gretel"<<endl;   // i.e Hansel won!
        else
            cout<<"Hansel"<<endl;
    }
}
