#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

typedef pair<int, int> ii;
map<string, ii> dP;

bool isWon(string &tTac, char x) {
    for(int i=0; i<4; i++) {
        if(tTac[i*4+0]==x && tTac[i*4+1]==x && tTac[i*4+2]==x && tTac[i*4+3]==x) return true;
        if(tTac[0*4+i]==x && tTac[1*4+i]==x && tTac[2*4+i]==x && tTac[3*4+i]==x) return true;
    }

    if(tTac[0*4+0]==x && tTac[1*4+1]==x && tTac[2*4+2]==x && tTac[3*4+3]==x) return true;
    if(tTac[0*4+3]==x && tTac[1*4+2]==x && tTac[2*4+1]==x && tTac[3*4+0]==x) return true;

    return false;
}

bool isPos(string &tTac) {
    bool isPossible;

    for(int i=0; i<4; i++) {
        isPossible=true;
        if(tTac[i*4+0]=='o' || tTac[i*4+1]=='o' || tTac[i*4+2]=='o' || tTac[i*4+3]=='o') isPossible=false;
        if(isPossible) return true;
    }

    for(int i=0; i<4; i++) {
        isPossible=true;
        if(tTac[0*4+i]=='o' || tTac[1*4+i]=='o' || tTac[2*4+i]=='o' || tTac[3*4+i]=='o') isPossible=false;
        if(isPossible) return true;
    }

    isPossible=true;
    if(tTac[0*4+0]=='o' || tTac[1*4+1]=='o' || tTac[2*4+2]=='o' || tTac[3*4+3]=='o') isPossible=false;
    if(isPossible) return true;

    isPossible=true;
    if(tTac[0*4+3]=='o' || tTac[1*4+2]=='o' || tTac[2*4+1]=='o' || tTac[3*4+0]=='o') isPossible=false;
    if(isPossible) return true;

    return false;
}

ii findXPos(int p, string ticTac) {
    if(dP.find(ticTac)!=dP.end())
        return dP[ticTac];

    if(isPos(ticTac)==false) {
        dP[ticTac]=ii(-1,-1);
        return ii(-1,-1);
    }

    if(p==0) {
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                if(ticTac[i*4+j]=='.') {
                    ticTac[i*4+j]='x';

                    if(isWon(ticTac, 'x')) {
                        dP[ticTac]=ii(i,j);
                        return ii(i,j);
                    }

                    ii res=findXPos(1, ticTac);
                    if(res.first!=-1) {
                        dP[ticTac]=ii(i,j);
                        return ii(i,j);
                    }

                    ticTac[i*4+j]='.';
                }

        dP[ticTac]=ii(-1,-1);
        return ii(-1,-1);
    }
    else {
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                if(ticTac[i*4+j]=='.') {
                    ticTac[i*4+j]='o';

                    if(isWon(ticTac, 'o')) {
                        dP[ticTac]=ii(-1,-1);
                        return ii(-1,-1);
                    }

                    ii res=findXPos(0, ticTac);
                    if(res.first==-1) {
                        dP[ticTac]=ii(-1,-1);
                        return ii(-1,-1);
                    }

                    ticTac[i*4+j]='.';
                }

        dP[ticTac]=ii(0,0);
        return ii(0,0);
    }
}

int main() {
    char c;
    string ticTac;

    cin>>c;
    while(c!='$') {
        ticTac="";

        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++) {
                cin>>c; ticTac+=c;
            }

        ii res=findXPos(0, ticTac);
        if(res.first!=-1) cout<<"("<<res.first<<","<<res.second<<")"<<endl;
        else cout<<"#####"<<endl;

        cin>>c;
    }
}
