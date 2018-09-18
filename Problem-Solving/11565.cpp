#include<iostream>
using namespace std;

int main() {
    int t;
    long long a,b,c;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        cin>>a>>b>>c;

        bool cflag=false;
        long long x=0, y,z;

        x=-10000;
        while(x<0) {
            y=x+1;

            while(y<0 && x*y<10000) {
                z=(a-(x+y));
                if(z!=x && z!=y && x*y*z==b && x*x+y*y+z*z==c) {
                    cout<<x<<" "<<y<<" "<<z<<endl;
                    cflag=true;
                    break;
                }
                y++;
            }

            if(cflag) break;
            x++;
        }

        x=0;
        if(!cflag)
        while(x<=a) {
            y=x+1;

            while(y<=(a-x)) {
                z=(a-(x+y));
                if(z!=x && z!=y && x*y*z==b && x*x+y*y+z*z==c) {
                    cout<<x<<" "<<y<<" "<<z<<endl;
                    cflag=true;
                    break;
                }
                y++;
            }

            if(cflag) break;
            x++;
        }

        if(!cflag) cout<<"No solution."<<endl;
    }
}
