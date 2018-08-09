#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > vvi;
vector<vvi> vMap;

int rS[]={-1,0,1,0}, cS[]={0,-1,0,1};

int printN(int n) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            cout<<vMap[n][i][j];
        cout<<endl;
    }

    cout<<endl;
}

bool isZero(int n) {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(vMap[n][i][j]==1) return false;

    return true;
}

int getFinite() {
    int n=0,r,c;

    while(!isZero(n)) {
        n++;
        vMap[n].assign(3,vector<int>());
        for(int i=0; i<3; i++) {
            vMap[n][i].assign(3,0);
            for(int j=0; j<3; j++) {
                int res=0;
                for(int k=0; k<4; k++) {
                    r=i+rS[k]; c=j+cS[k];
                    if(r<3&&r>=0 && c<3&&c>=0 && vMap[n-1][r][c]==1) res++;
                }
                vMap[n][i][j]=res%2;
            }
        }
        //printN(n);
    }

    return n-1;
}

int main() {
    int t;
    char tN;
    vMap.assign(100000, vvi());

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t;
    while(t--) {
        vMap[0].assign(3,vector<int>());
        for(int i=0; i<3; i++) {
            vMap[0][i].assign(3,0);
            for(int j=0; j<3; j++) {
                cin>>tN; vMap[0][i][j]=tN-'0';
            }
        }
        //printN(0);
        cout<<getFinite()<<endl;
    }
 }
