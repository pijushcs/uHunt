#include<iostream>
#include<cmath>
using namespace std;

#define EPS 1e-9

double p,q,r,s,t,u;

double sol(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double findSolSimple(double lo, double hi) {
    double mid;
    if(sol(lo)==0.0) return lo;
    if(sol(hi)==0.0) return hi;

    if(sol(lo)*sol(hi)>0.0) return -1.0;

    while(abs(hi-lo)>EPS) {
        mid=(lo+hi)/2;

        if(sol(mid)==0.0) return mid;
        if(sol(lo)*sol(mid)<0) // i.e the curve from f(low) to f(mid) passes through 0
            hi=mid;
        else
            lo=mid;
    }

    return mid;
}

double findSol(double lo, double hi) {
    double a=sol(lo), b=sol(hi), mid;
    bool isHigh=false;

    if(a==0) return lo;
    if(b==0) return hi;

    // curve doesn't pass through 0
    if((a>0 && b>0) || (a<0 && b<0)) return -1.0;

    // isHigh is true is curve has the following feature, [f(lo):-y, f(hi):+y]
    // In case, [f(lo):+y, f(hi):-y], isHigh is false
    if(b>a) isHigh=true;

    while(abs(hi-lo)>EPS) {
        mid=(hi+lo)/2;

        double res=sol(mid);
        if(res==0.0) return mid;

        if(isHigh && res>0) hi=mid;
        else if(res>0) lo=mid;

        if(isHigh && res<0) lo=mid;
        else if(res<0) hi=mid;
    }

    return mid;
}

int main() {
    freopen("testCase.txt", "r", stdin);
    freopen("testOut-2.txt", "w", stdout);

    while((cin>>p)) {
        cin>>q>>r>>s>>t>>u;

        double res=findSolSimple(0,1);
        if(res==-1) cout<<"No solution"<<endl;
        else printf("%0.4f\n", res);
    }
}
