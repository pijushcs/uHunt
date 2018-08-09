#include <iostream>
using namespace std;

char A[1000][1000];
char B[1000][1000];

void rotateMat(char mat[][1000], int pos, int n) {
    int temp;
    if(n<=1) return;

    for(int i=0; i<n-1; i++) {
        temp=mat[pos][pos+i];
        mat[pos][pos+i]=mat[pos+n-1-i][pos];
        mat[pos+n-1-i][pos]=mat[pos+n-1][pos+n-1-i];
        mat[pos+n-1][pos+n-1-i]=mat[pos+i][pos+n-1];
        mat[pos+i][pos+n-1]=temp;
    }

    rotateMat(mat, pos+1, n-2);
}

int isMatch(int nA, int nB, int r, int c) {
    for(int i=0; i<nB; i++)
        for(int j=0; j<nB; j++)
            if(A[r+i][c+j]!=B[i][j])
                return 0;
    return 1;
}

long long findMatch(int nA, int nB) {
    long long res=0;

    for(int i=0; i<=nA-nB; i++)
        for(int j=0; j<=nA-nB; j++)
            if(B[0][0]==A[i][j])
                res+=isMatch(nA, nB, i, j);

    return res;
}

void rotateMatch(int nA, int nB) {
    for(int i=0; i<4; i++) {
        cout<<findMatch(nA, nB);

        if(i<3) {
            cout<<" "; rotateMat(B,0,nB);
        }
        else
            cout<<endl;
    }
}

void printMat(int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
int main() {
    int nA, nB;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);
    cin>>nA>>nB;
    while(nA!=0 || nB!=0) {
        for(int i=0;i<nA;i++)
            for(int j=0;j<nA;j++)
                cin>>A[i][j];

        for(int i=0;i<nB;i++)
            for(int j=0;j<nB;j++)
                cin>>B[i][j];

        rotateMatch(nA, nB);
        //rotateMat(A,0,nA);
        //printMat(nA);
        cin>>nA>>nB;
    }
}
