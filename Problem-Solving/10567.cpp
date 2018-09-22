#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef vector<int> vi;

pair<int, int> spos;
string sseq;
map<char, vector<int> > mpos;

bool isMatch(string &squery) {
    int pos=mpos[squery[0]][0];
    spos.first=pos;

    for(int i=1; i<squery.length(); i++) {
        char cq=squery[i];
        vi::iterator ipos=lower_bound(mpos[cq].begin(), mpos[cq].end(), pos+1);

        if(ipos==mpos[cq].end()) return false;
        pos=*ipos;
    }

    spos.second=pos;
    return true;
}

int main() {
    int n;
    string squery;

    freopen("testCase.txt", "r", stdin);

    cin>>sseq;
    for(int i=0; i<sseq.length(); i++)
        mpos[sseq[i]].push_back(i);

    cin>>n;
    while(n--) {
        cin>>squery;
        if(isMatch(squery)) cout<<"Matched "<<spos.first<<" "<<spos.second<<endl;
        else cout<<"Not matched"<<endl;
    }
}
