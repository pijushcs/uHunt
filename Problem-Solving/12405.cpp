#include<iostream>
using namespace std;

int main() {
    int t, ncrow, n, pos, tcase=1;
    char vcrop[101];

    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>vcrop[i];

        ncrow=0; pos=0;
        while(pos<n) {
            if(vcrop[pos]=='.') {
                ncrow++;
                pos+=3;
            }
            else pos++;
        }

        cout<<"Case "<<tcase++<<": "<<ncrow<<endl;
    }
}
