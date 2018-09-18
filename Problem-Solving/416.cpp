#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

vector<vector<string> > vsled;
vector<string> sled;
map<string, int> mled;

// starting from 1 since mled[str]==0 is set as default
void genNum() {
    mled["YYYYYYN"]=1;
    mled["NYYNNNN"]=2;
    mled["YYNYYNY"]=3;
    mled["YYYYNNY"]=4;
    mled["NYYNNYY"]=5;
    mled["YNYYNYY"]=6;
    mled["YNYYYYY"]=7;
    mled["YYYNNNN"]=8;
    mled["YYYYYYY"]=9;
    mled["YYYYNYY"]=10;
}

// p: led index, k: current #led, n: total #led
void buildLed(int p, int k, int n, string &led) {
    bool isBurned=true;

    if(p==8 && mled[led]!=0) {
        vsled[k].push_back(led);
        return;
    }

    if(p==8) return;

    for(int i=k; i<n; i++) {
        if(sled[i][p]!='N') {
            isBurned=false;
            break;
        }
    }

    if(isBurned) {
        led[p]='Y';
        buildLed(p+1, k, n, led);
        led[p]='N';
    }

    buildLed(p+1, k, n, led);
}

//k: current #led, n: total #led, pled: previous led->digit;
bool isMatch(int k, int n, int pled) {
    if(k==n) return true;

    bool res=false;
    for(int i=0; i<vsled[k].size(); i++) {
        string led=vsled[k][i];
        int nled=mled[led];

        if(k==0) res=isMatch(k+1, n, nled);
        else if(nled==pled-1) res=isMatch(k+1, n, nled);

        if(res) return true;
    }

    return res;
}

int main() {
    int n;
    string led;

    genNum();

    freopen("testCase.txt", "r", stdin);

    cin>>n;
    while(n!=0) {
        sled.clear();
        for(int i=0; i<n; i++) {
            cin>>led;
            sled.push_back(led);
        }

        vsled.assign(n, vector<string>());
        for(int i=0; i<n; i++) {
            string tled=sled[i];
            buildLed(0, i, n, tled);
        }

        if(isMatch(0, n, 0)) cout<<"MATCH"<<endl;
        else cout<<"MISMATCH"<<endl;

        cin>>n;
    }
}
