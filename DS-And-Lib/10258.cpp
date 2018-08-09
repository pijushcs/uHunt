#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

map<int, vii> mapCons;
map<int, int> mapTime;
map<int, int> mapQues;

vector<int> vCons;

void addQuestion(int cons, int ques, int time, char L) {
    if(mapCons[cons].empty()) {
        mapCons[cons].assign(10,ii(0,0));
        vCons.push_back(cons);
    }

    int curTime=mapCons[cons][ques].second;
    if(L=='C' && mapCons[cons][ques].first==0) {
        mapQues[cons]=mapQues[cons]+1;
        mapCons[cons][ques].first=1;
        mapTime[cons]=mapTime[cons]+time+curTime;
    }
    if(L=='I' && mapCons[cons][ques].first==0)
        mapCons[cons][ques].second=curTime+20;
}

bool rankComp(int consA, int consB) {
    if(mapQues[consA]>mapQues[consB]) return true;
    if(mapQues[consA]<mapQues[consB]) return false;

    if(mapTime[consA]<mapTime[consB]) return true;
    if(mapTime[consA]>mapTime[consB]) return false;

    if(consA<consB) return true;
    return false;
}

void init() {
    mapQues.clear();
    mapTime.clear();
    mapCons.clear();
    vCons.clear();
}

int main() {
    int n, cons, ques, time;
    string str;
    char L;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n;
    getline(cin, str); getline(cin, str); // for \n and blank line

    while(n--) {
        init();
        getline(cin,str);
        while(str.size()!=0) {
            sscanf(str.c_str(), "%d %d %d %c", &cons, &ques, &time, &L);
            addQuestion(cons, ques, time, L);
            getline(cin,str);
        }

        sort(vCons.begin(), vCons.end(), rankComp);
        for(int i=0; i<vCons.size(); i++) {
            int tCons=vCons[i];
            cout<<tCons<<" "<<mapQues[tCons]<<" "<<mapTime[tCons]<<endl;
        }
        if(n) cout<<endl;
    }
}

