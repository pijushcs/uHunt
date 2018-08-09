#include<iostream>
#include<stack>
#include<queue>
using namespace std;

bool sFlag, qFlag, pFlag;

void testStructure(int n) {
    int opx, val;
    priority_queue<int> pTest;
    queue<int> qTest;
    stack<int> sTest;

    sFlag=true; qFlag=true; pFlag=true;

    while(n--) {
        cin>>opx>>val;
        //cout<<opx<<" "<<val<<endl;

        if(opx==1) {
            if(sFlag) sTest.push(val);
            if(qFlag) qTest.push(val);
            if(pFlag) pTest.push(val);
        }
        else {
            if(!sTest.empty() && sTest.top()==val) sTest.pop();
            else sFlag=false;

            if(!qTest.empty() && qTest.front()==val) qTest.pop();
            else qFlag=false;

            if(!pTest.empty() && pTest.top()==val) pTest.pop();
            else pFlag=false;
        }
    }

    if(pFlag && qFlag && sFlag || pFlag && qFlag || pFlag && sFlag || qFlag && sFlag) cout<<"not sure"<<endl;
    else if(pFlag) cout<<"priority queue"<<endl;
    else if(sFlag) cout<<"stack"<<endl;
    else if(qFlag) cout<<"queue"<<endl;
    else cout<<"impossible"<<endl;
}

int main() {
    int n;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    while((cin>>n)) {
        testStructure(n);
    }
}
