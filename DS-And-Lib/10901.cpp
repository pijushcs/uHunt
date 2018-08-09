#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

typedef pair<int,int> ii;

queue<int> qLeft, qRight, sFerry;
map<string, queue<int> > res;
vector<string> vInput;

void timeTaken(int n, int t, int tCar) {
    int curPos=0; //0=left, 1=right;
    int curCar=0, curS;
    int curTime=0;

    bool flgCar;

    while(curCar<tCar) {
        if(!curPos) {
            flgCar=false;
            curS=0;
            while(curS<n && !qLeft.empty() && qLeft.front()<=curTime) {
                curS++;
                sFerry.push(qLeft.front());
                qLeft.pop();
                flgCar=true;
            }

            if(!flgCar && ((!qLeft.empty() && !qRight.empty() && qLeft.front()<=qRight.front()) || (!qLeft.empty() && qRight.empty()))) {
                curTime=qLeft.front();
                while(!qLeft.empty() && qLeft.front()<=curTime) {
                    curS++;
                    sFerry.push(qLeft.front());
                    qLeft.pop();
                }
            }
            else if(!flgCar && !qRight.empty() && curTime<qRight.front()){
                curTime=qRight.front();
            }

            curTime+=t;

            curCar+=curS;
            while(curS--) {
                res["l"+to_string(sFerry.front())].push(curTime);
                sFerry.pop();
            }

            curPos=1;
        }
        else {
            flgCar=false;
            curS=0;
            while(curS<n && !qRight.empty() && qRight.front()<=curTime) {
                curS++;
                sFerry.push(qRight.front());
                qRight.pop();
                flgCar=true;
            }

            if(!flgCar && (!qRight.empty() && !qLeft.empty() && qRight.front()<=qLeft.front() || !qRight.empty() && qLeft.empty())) {
                curTime=qRight.front();
                while(!qRight.empty() && qRight.front()<=curTime){
                    curS++;
                    sFerry.push(qRight.front());
                    qRight.pop();
                }
            }
            else if(!flgCar && !qLeft.empty() && curTime<qLeft.front()) curTime=qLeft.front();

            curTime+=t;

            curCar+=curS;
            while(curS--) {
                res["r"+to_string(sFerry.front())].push(curTime);
                sFerry.pop();
            }
            curPos=0;
        }
    }

    //sort(res.begin(), res.end());
    //for(int i=0; i<res.size(); i++)
        //cout<<res[i].second<<endl;
}

int main() {
    int tn, n, t, m, curT, tCar;
    string strPos;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);
    cin>>tn;
    while(tn--) {
        cin>>n>>t>>m;

        tCar=m;
        vInput.clear();
        res.clear();

        while(m--) {
            cin>>curT>>strPos;

            if(!strPos.compare("left")) {
                qLeft.push(curT);
                vInput.push_back("l"+to_string(curT));
            }
            else {
                qRight.push(curT);
                vInput.push_back("r"+to_string(curT));
            }
        }

        timeTaken(n,t,tCar);
        for(int i=0; i<vInput.size(); i++) {
            cout<<res[vInput[i]].front()<<endl;
            res[vInput[i]].pop();
        }
        if(tn) cout<<endl;
    }
}
