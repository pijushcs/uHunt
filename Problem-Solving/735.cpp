#include<iostream>
#include<vector>
using namespace std;

int getComp(int n, int k, int ci) {
    if(n<0) return 0;
    if(k==3 && n==0) return 1;
    if(k==3) return 0;

    int res=0;
    for(int i=ci; i<=60; i++) {
        if(i==50 || i<=20 || ((i%2)==0 && (i/2)<=20) || ((i%3)==0 && (i/3)<=20))
            res+=getComp(n-i,k+1,i);
    }

    return res;
}

int getPerm(int n, int k) {
    if(n<0) return 0;
    if(k==3 && n==0) return 1;
    if(k==3) return 0;

    int res=0;
    for(int i=0; i<=60; i++) {
        if(i==50 || i<=20 || ((i%2)==0 && (i/2)<=20) || ((i%3)==0 && (i/3)<=20))
            res+=getPerm(n-i,k+1);
    }

    return res;
}

/*************************************************************
int getPerm(int n, int k) {
    vector<bool> nmap;
    nmap.assign(100, false);

    if(n<0) return 0;
    if(k==3 && n==0) return 1;
    if(k==3) return 0;

    int res=0;
    for(int i=-1; i<=20; i++) {
        if(i==-1 && nmap[50]==false) {
            res+=getPerm(n-50,k+1);
            nmap[50]=true;
        }
        else {
            if(nmap[i]==false) {
                res+=getPerm(n-i,k+1); nmap[i]=true;
            }
            if(nmap[2*i]==false) {
                res+=getPerm(n-2*i,k+1); nmap[2*i]=true;
            }
            if(nmap[3*i]==false) {
                res+=getPerm(n-3*i,k+1); nmap[3*i]=true;
            }
        }
    }

    return res;
}
*************************************************************/

int main() {
    int m;

    cin>>m;
    while(m>0) {

        int cres=getComp(m,0,0);
        int pres=getPerm(m,0);

        if(cres) {
            cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<m<<" IS "<<cres<<"."<<endl;
            cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<m<<" IS "<<pres<<"."<<endl;
        }
        else
            cout<<"THE SCORE OF "<<m<<" CANNOT BE MADE WITH THREE DARTS."<<endl;

        cout<<"**********************************************************************"<<endl;
        cin>>m;
    }

    cout<<"END OF OUTPUT"<<endl;
}
