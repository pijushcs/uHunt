#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

typedef pair<int, int> ii;
map<ii, int> dP;
vector<int> vdigit;

// Not sure how dP[p][csum] worked here! The ideal way is to use the bitmask as the second parameter
// I will try to upload a proof of how the choice of digits in the mask didn't matter later
int winGame(int p, string smask, vector<int> &vdigit, int csum) {
    int wgame;
    bool mdigit[10]={false};
    if(dP.find(ii(p,csum))!=dP.end()) return dP[ii(p,csum)];

    if(p==1) {
        wgame=1;
        for(int i=0; i<vdigit.size(); i++) {
            if(smask[i]=='0' && (csum-vdigit[i])%3==0 && mdigit[vdigit[i]]==false) {
                mdigit[vdigit[i]]=true; smask[i]='1';
                wgame=winGame(0, smask, vdigit, csum-vdigit[i]);
                smask[i]='0';

                if(wgame==0) {
                    dP[ii(p,csum)]=wgame;
                    return wgame;
                }
            }
        }
        dP[ii(p,csum)]=wgame;
    }
    else {
        wgame=0;
        for(int i=0; i<vdigit.size(); i++) {
            if(smask[i]=='0' && (csum-vdigit[i])%3==0 && mdigit[vdigit[i]]==false) {
                mdigit[vdigit[i]]=true; smask[i]='1';
                wgame=winGame(1, smask, vdigit, csum-vdigit[i]);
                smask[i]='0';

                if(wgame) {
                    dP[ii(p,csum)]=wgame;
                    return wgame;
                }
            }
        }
        dP[ii(p,csum)]=wgame;
    }

    return wgame;
}

int main() {
    int t, tcase=1,csum=0;
    string sdigit, str, smask;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>t; getline(cin, str);
    while(t--) {
        getline(cin, sdigit);
        smask="";

        vdigit.clear(); dP.clear(); csum=0;
        for(int i=0; i<sdigit.length(); i++) {
            vdigit.push_back((sdigit[i]-'0'));
            smask+='0';
            csum+=(sdigit[i]-'0');
        }

        if(winGame(0, smask, vdigit, csum)) cout<<"Case "<<tcase++<<": S"<<endl;
        else cout<<"Case "<<tcase++<<": T"<<endl;
    }
}
