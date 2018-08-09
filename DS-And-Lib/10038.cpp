#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n=1;
    string str;
    int numx,tSum,prev,diff;
    bitset<4000> bitMask;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>n)) {

        if(n) {
            tSum=0;
            bitMask.reset();

            for(int i=0; i<n; i++) {
                cin>>numx;
                if(i>0) diff=abs(numx-prev);

                if(i>0 && bitMask[diff] == 0) {
                    bitMask.set(diff);
                    tSum += diff;
                }

                prev=numx;
            }

            if(tSum==(n-1)*n/2 || n==1) cout<<"Jolly"<<endl;
            else cout<<"Not jolly"<<endl;
        }

    }
}
