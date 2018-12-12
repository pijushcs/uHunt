#include<iostream>
using namespace std;

int main() {
    int n, tcase=1;
    long long nedges, ngroup;

    cin>>n;
    while(n) {
        nedges=n*(n-1)/2; // #edges for complete graph is nC2

        // Now, each MST must have (n-1) edges. Since we need unique MST(s),
        // we can divide all the #edges to groups of (n-1) and each group signifies
        // a separate MST. So, no of groups of (n-1) form the #edges:

        ngroup=nedges/(n-1); // can be simplified to n/2
        cout<<"Case "<<tcase++<<": "<<ngroup<<endl;

        cin>>n;
    }
}
