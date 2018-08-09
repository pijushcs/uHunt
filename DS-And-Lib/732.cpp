#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<char> res;
stack<int> wStack;

void printRes() {
    for(int i=0; i<res.size(); i++) {
        cout<<res[i];
        if(i!=res.size()-1) cout<<" ";
    }
    cout<<endl;
}

void printPossible(string &origStr, string &anagStr, stack<int> &wStack, int pOrig, int pAnag) {
    if(pAnag>=anagStr.length())
        printRes();

    if(pOrig<origStr.length()) {
        wStack.push(origStr[pOrig]);
        res.push_back('i');

        printPossible(origStr, anagStr, wStack, pOrig+1, pAnag);

        wStack.pop();
        res.pop_back();
    }

    if(!wStack.empty() && wStack.top()==anagStr[pAnag]) {
        wStack.pop();
        res.push_back('o');

        printPossible(origStr, anagStr, wStack, pOrig, pAnag+1);

        res.pop_back();
        wStack.push(anagStr[pAnag]);
    }
}

int main() {
    string orig, anag;

    freopen("testCase.txt", "r", stdin);
    while((cin>>orig)) {
        cin>>anag;

        cout<<"["<<endl;
        printPossible(orig, anag, wStack, 0, 0);
        cout<<"]"<<endl;
    }
}
