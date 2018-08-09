#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> vString;

int pos;

int beijuText(int vIndex, string &str) {
    int curIndex=vIndex;

    vString.push_back("");

    while(pos<str.length()) {
        if(str[pos] == '[') {
            pos++;
            vIndex=beijuText(vIndex+1, str);
        }
        else if(str[pos]==']') {
            pos++;
            return vIndex;
        }
        else {
            vString[curIndex]+=str[pos];
            pos++;
        }

    }

    return vIndex;
}

void printStr(int rIndex, string &str) {
    for(int i=rIndex; i>=0; i--)
        cout<<vString[i];
    cout<<endl;
}

int main() {
    string str;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    getline(cin, str);
    while(str.compare("")) {
        pos=0;
        vString.clear();

        int resIndex=beijuText(0,str);

        printStr(resIndex, str);
        getline(cin, str);
    }
}
