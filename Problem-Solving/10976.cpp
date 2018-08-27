#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vii vRes;

int main() {
    int k,n=0;
    double x,y;

    while((cin>>k)) {
        vRes.clear();
        for(int i=k+1; i<=2*k; i++) {
            x=i; y=(x*k)/(x-k);
            if(fmod(y,(int)y)==0) vRes.push_back(ii((int)y, (int)x));
        }

        cout<<vRes.size()<<endl;
        for(int i=0; i<vRes.size(); i++)
            cout<<"1/"<<k<<" = 1/"<<vRes[i].first<<" + 1/"<<vRes[i].second<<endl;
    }
}
