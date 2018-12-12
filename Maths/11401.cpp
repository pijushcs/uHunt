#include<iostream>
#include<cstring>
using namespace std;

long long dP[1000002];

/****************************************************************
* A small explanation:                                          *
* vedges be {1,2,3....n}. Let #triangles with n edges be dP[n]  *
* So, dP[n] = dP[n-1] + #triangles with n as the longest edge   *
*                                                               *
* Visualizing #triangles with n as the longest edge:            *
* {#x,#y,n}, x,y -> [1,n-1]. Now for all x,y, n+x>y and n+y>x   *
* since n > (x,y). So, we just need to find x,y such that x+y>n *
*                                                               *
* If x=1, y > n-1, i.e y must be >=n and n is already selected. *
* So, #Y-count: 0. If x=2, y>n-2, i.e y = {n-1} #Y-count: 1     *
* Similarly for x=3, y = {n-1,n-2} and for x=4, y={n-1,n-2,n-3} *
* and Y-count: 2 and 3 respectively.                            *
*                                                               *
* But if x>n/2, y>n-n/2:                                        *
* i.e y = {n-(n/2)+1, ..., and all numbers on right of x}       *
* So, #Y-count increases to n/2 and then decreases to 1         *
* For 6, Y-count: {0,1,2,1,0} for x={1,2,3,4,5} and for 7,      *
* Y-count: {0,1,2,2,1,0} for x={1,2,3,4,5,6}                    *
*                                                               *
* Thus, #triangles with n as the longest edge (#nres) is:       *
* for odd n: sum(1...n/2-1) + sum(n/2-1...1) = 2*sum(1...n/2-1) *
* for odd n: 2*sum(1...n/2-1) - (n/2-1)                         *
*                                                               *
* So, #triangles with all n edges: dP[n-1] + #nres              *
****************************************************************/

long long findTriangle(int n) {
    long long res, nres;

    if(n<4) return 0;
    if(dP[n]!=0) return dP[n];

    nres = ((n/2-1)*(long long)(n/2)); // simplifying 2 * ((n/2-1)*((n/2-1+1)))/2
    if(n%2==0) nres-=(n/2-1);

    res=findTriangle(n-1)+nres;

    dP[n]=res;
    return res;
}

int main() {
    int n;
    memset(dP, 0, 1000002*sizeof(long long));

    for(int i=4; i<1000001; i++)
        findTriangle(i);

    cin>>n;
    while(n>2) {
        cout<<findTriangle(n)<<endl;
        cin>>n;
    }
}
