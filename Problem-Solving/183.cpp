#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef vector<string> vs;

int xpos;

void sbitMap(vs &bitMap, int tr, int tc, int br, int bc) {
    char p=bitMap[tr][tc];
    int rmid, cmid;

    bool isSame=true;
    for(int i=tr; i<=br; i++) {
        for(int j=tc; j<=bc; j++) {
            if(bitMap[i][j]!=p) {
                isSame=false;
                break;
            }
        }

        if(!isSame) break;
    }

    if(isSame) {
        if(xpos>1 && xpos%50==1) cout<<endl;
        xpos++;
        cout<<p;
        return;
    }

    if(xpos> 1 && xpos%50==1) cout<<endl;
    cout<<"D";
    xpos++;

    if((bc-tc+1)%2==0) cmid=tc+(bc-tc+1)/2;
    else if((bc-tc+1)%2==1) cmid=tc+(bc-tc+1)/2+1;

    if((br-tr+1)%2==0) rmid=tr+(br-tr+1)/2;
    else if((br-tr+1)%2==1) rmid=tr+(br-tr+1)/2+1;

    if(br!=tr && bc!=tc) {
        sbitMap(bitMap, tr, tc, rmid-1, cmid-1);
        sbitMap(bitMap, tr, cmid, rmid-1, bc);
        sbitMap(bitMap, rmid, tc, br, cmid-1);
        sbitMap(bitMap, rmid, cmid, br, bc);
        return;
    }

    if(br==tr) {
        sbitMap(bitMap, tr, tc, tr, cmid-1);
        sbitMap(bitMap, tr, cmid, tr, bc);
        return;
    }

    if(bc==tc) {
        sbitMap(bitMap, tr, tc, rmid-1, tc);
        sbitMap(bitMap, rmid, tc, br, tc);
        return;
    }
}

char matBit[202][202];
int dbitMap(string &bitMap, int pos, int tr, int tc, int br, int bc) {
    //cout<<pos<<" "<<tr<<" "<<tc<<" "<<br<<" "<<bc<<endl;
    if(bitMap[pos]!='D') {
        //cout<<"X";
        for(int i=tr; i<=br; i++)
            for(int j=tc; j<=bc; j++)
                matBit[i][j]=bitMap[pos];
        return pos+1;
    }

    int rmid, cmid;

    if((br-tr+1)%2) rmid=tr+(br-tr+1)/2+1;
    else if((br-tr+1)%2==0) rmid=tr+(br-tr+1)/2;

    if((bc-tc+1)%2) cmid=tc+(bc-tc+1)/2+1;
    else if((bc-tc+1)%2==0) cmid=tc+(bc-tc+1)/2;


    if(tr!=br && tc!=bc) {
        //if(cmid < 0) cout<<"P"<<tr<<" "<<tc<<" "<<br<<" "<<bc;
        pos=dbitMap(bitMap, pos+1, tr, tc, rmid-1, cmid-1);
        pos=dbitMap(bitMap, pos, tr, cmid, rmid-1, bc);
        pos=dbitMap(bitMap, pos, rmid, tc, br, cmid-1);
        pos=dbitMap(bitMap, pos, rmid, cmid, br, bc);
        return pos;
    }

    if(tr==br) {
        //if(cmid < 0) cout<<"Y"<<tr<<" "<<tc<<" "<<br<<" "<<bc;
        pos=dbitMap(bitMap, pos+1, tr, tc, tr, cmid-1);
        pos=dbitMap(bitMap, pos, tr, cmid, tr, bc);
        return pos;
    }

    if(tc==bc) {
        //if(rmid < 0) cout<<"Z"<<tr<<" "<<tc<<" "<<br<<" "<<bc;
        pos=dbitMap(bitMap, pos+1, tr, tc, rmid-1, tc);
        pos=dbitMap(bitMap, pos, rmid, tc, br, tc);
        return pos;
    }
}

int main() {
    int n,m;
    char op;
    string cstr, bstr;
    vs bitMap;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut-2.txt", "w", stdout);

    getline(cin, cstr);
    while(cstr.compare("#")) {
        sscanf(cstr.c_str(), "%c %d %d", &op, &n, &m);

        if(cstr[0]=='D') cstr[0]='B';
        else cstr[0]='D';

        cout<<cstr[0];
        if(n<10) cout<<"   "<<n;
        else if(n<100) cout<<"  "<<n;
        else cout<<" "<<n;

        if(m<10) cout<<"   "<<m<<endl;
        else if(m<100) cout<<"  "<<m<<endl;
        else cout<<" "<<m<<endl;

        bitMap.clear();

        bstr="";
        getline(cin, cstr);
        while(cstr.find("D ")==-1 && cstr.find("B ")==-1 && cstr.compare("#")) {
            bstr+=cstr;
            getline(cin, cstr);
        }

        int pos=0;

        if(op=='B') {
            for(int i=0; i<n; i++) {
                bitMap.push_back("");
                for(int j=0; j<m; j++)
                    bitMap[i]+=bstr[pos++];
            }

            xpos=1;
            sbitMap(bitMap, 0, 0, n-1, m-1);
        }
        else {
            dbitMap(bstr, 0, 0, 0, n-1, m-1);

            xpos=1;
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++) {
                    if(xpos>1 && xpos%50==1) cout<<endl;
                    cout<<matBit[i][j];
                    xpos++;
                }
        }

        cout<<endl;
    }
}
