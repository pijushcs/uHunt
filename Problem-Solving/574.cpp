#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> vres, vset;
map<vector<int>, bool> mapSol;
bool pflag;

void printSol() {
    if(mapSol[vres]) return;
    pflag=true;

    cout<<vres[0];
    for(int i=1; i<vres.size(); i++)
        cout<<"+"<<vres[i];
    cout<<endl;

    mapSol[vres]=true;
}

void printSum(int p, long long sum) {
    if(sum==0) {
        printSol();
        return;
    }

    if(p==vset.size()) return;


    vres.push_back(vset[p]);
    printSum(p+1, sum-vset[p]);
    vres.pop_back();

    printSum(p+1, sum);
}

int main() {
    int t,n,val;

    cin>>t>>n;
    while(n!=0 && t!=0) {
        vres.clear(); vset.clear();
        mapSol.clear(); pflag=false;

        for(int i=0; i<n; i++) {
            cin>>val;
            vset.push_back(val);
        }

        cout<<"Sums of "<<t<<":"<<endl;
        printSum(0, t);
        if(!pflag) cout<<"NONE"<<endl;

        cin>>t>>n;
    }
}
