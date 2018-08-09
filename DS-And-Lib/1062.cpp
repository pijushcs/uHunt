#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<stack<char> > curVec;

int nStack(string str) {
    int j, res=0;
    for(int i=0; i<str.length(); i++) {
        for(j=0; j<curVec.size(); j++)
            if(curVec[j].top()>=str[i]){
                curVec[j].push(str[i]);
                break;
            }

        if(j==curVec.size()) {
            curVec.push_back(stack<char>());
            curVec[j].push(str[i]);
            res++;
        }
    }

    return res;
}

int main() {
    string str;
    int k=1;

    cin>>str;
    while(str.compare("end")) {
        curVec.clear();
        cout<<"Case "<<k++<<": "<<nStack(str)<<endl;
        cin>>str;
    }
}
