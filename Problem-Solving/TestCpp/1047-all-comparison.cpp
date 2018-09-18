#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

vector<int> vzone, vres, tzone, vzoneVal;
map<string, long long> mzone;

long long maxNow;
string delim="x";

string makeDelimStr() {
    string res="";

    for(int i=0; i<tzone.size(); i++)
        res+=to_string(tzone[i])+delim;

    return res;
}

// mCk
long long checkValCover(int m, int k, int p) {
    long long res=0;
    if(k==0) {
        string strZone=makeDelimStr();
        return mzone[strZone];
    }

    if(p==m) return 0;

    tzone.push_back(vzone[p]);
    res=checkValCover(m, k-1, p+1);
    tzone.pop_back();

    res+=checkValCover(m, k, p+1);

    return res;
}

void checkMaxCovered(int m) {
    long long nres, res=0;

    for(int i=0; i<m; i++) {
        res+=vzoneVal[vzone[i]-1];
    }

    for(int i=2; i<=m; i++) {
        nres=checkValCover(m,i,0);
        if(i%2) res+=nres;
        else res-=nres;
    }

    if(maxNow<res) {
        vres=vzone;
        maxNow=res;
    }
}

//nCm
void findZone(int n, int nm, int m, int p) {
    if(m==0) {
        checkMaxCovered(nm);
        return;
    }

    if(p>n) return;

    vzone.push_back(p);
    findZone(n,nm, m-1,p+1);
    vzone.pop_back();

    findZone(n,nm, m,p+1);
}

int main() {
    int n,m,t,nc, tcase=1;
    long long val;

    freopen("testCase.txt", "r", stdin);

    cin>>n>>m;
    while(n!=0 && m!=0) {
        //if(tcase>1) cout<<endl;

        vzoneVal.clear();
        for(int i=0; i<n; i++) {
            cin>>val; vzoneVal.push_back(val);
        }

        cin>>nc;
        mzone.clear();
        for(int i=0; i<nc; i++) {
            cin>>t;

            tzone.clear();
            for(int j=0; j<t; j++) {
                cin>>val; tzone.push_back(val);
            }

            cin>>val;
            string zstr=makeDelimStr();
            mzone[zstr]=val;
        }

        tzone.clear(); vzone.clear(); vres.clear();
        maxNow=0;

        findZone(n, m, m, 1);

        cout<<"Case Number "<<tcase++<<endl;
        cout<<"Number of Customers: "<<maxNow<<endl;
        cout<<"Locations recommended: "<<vres[0];

        for(int i=1; i<vres.size(); i++) cout<<" "<<vres[i];
        cout<<endl<<endl;

        cin>>n>>m;
    }
}
