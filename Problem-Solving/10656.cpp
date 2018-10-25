#include<iostream>
using namespace std;

int main() {
    int n;
    int val;

    cin>>n;
    while(n) {
        bool ptest=false;
        for(int i=0; i<n; i++) {
            cin>>val;
            if(val) {
                if(ptest) cout<<" ";
                ptest=true;
                cout<<val;
            }
        }
        if(!ptest) cout<<0;
        cout<<endl;

        cin>>n;
    }
}
