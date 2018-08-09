#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    string str;
    string sList;
    string::iterator it;
    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    getline(cin, str);
    while(str.compare("")) {
        sList="";
        it=sList.end();

        for(int i=0; i<str.length(); i++) {
            if(str[i]=='[')
                it=sList.begin();
            else if(str[i]==']')
                it=sList.end();
            else {
                it=sList.insert(it, str[i]);
                it++;
            }
        }

        cout<<sList<<endl;
        getline(cin, str);
    }
}
