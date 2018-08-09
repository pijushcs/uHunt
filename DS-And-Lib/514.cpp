#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isPossible(vector<int> distx) {
    stack<int> aStack;
    int curPos=1;

    for(int i=0; i<distx.size(); i++) {
        if(!aStack.empty() && aStack.top()==distx[i]) aStack.pop();
        else if(distx[i]>=curPos) {
            while(distx[i]>curPos) aStack.push(curPos++);
            if(curPos==distx[i]) curPos++;
            else return false;
        }
        else return false;
    }

    return true;
}

int main() {
    int n, k;
    vector<int> cVec;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>n;
    while(n!=0) {
        while(1) {
            cVec.clear();
            for(int i=0; i<n; i++) {
                cin>>k; if(k==0) break;
                cVec.push_back(k);
            }
            if(k==0) break;
            if(isPossible(cVec)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cin>>n;
        cout<<endl;
        //if(n!=0) cout<<endl;
    }
}
