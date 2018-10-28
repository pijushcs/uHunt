#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

double dP[501][501][501];

double findExp(int cpos, int lwin, int mwin, int n, double p) {
    double wres, lres;

    if(cpos==n)
        return (double)mwin;

    if(dP[cpos][lwin][mwin]>=0)
        return dP[cpos][lwin][mwin];

    if(lwin!=n) {
        if(mwin<cpos-lwin+1) wres=p*findExp(cpos+1, lwin, cpos-lwin+1, n, p);
        else wres=p*findExp(cpos+1, lwin, mwin, n, p);
    }
    else {
        if(mwin<1) wres=p*findExp(cpos+1, cpos, 1, n, p);
        else wres=p*findExp(cpos+1, cpos, mwin, n, p);
    }

    lres=(1.0-p)*findExp(cpos+1, n, mwin, n, p);

    dP[cpos][lwin][mwin]=wres+lres;
    return wres+lres;
}

int main() {
    int n; double p;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n>>p;
    while(n!=0) {

        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                for(int k=0; k<=n; k++) dP[i][j][k]=-1.0;

        printf("%f\n", findExp(0,n,0,n,p));
        cin>>n>>p;
    }
}
