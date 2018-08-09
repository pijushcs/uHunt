#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    string str;
    list<char> sList;
    list<char>::iterator it;
    //freopen("testCase.txt", "r", stdin);
    //freopen("testOut.txt", "w", stdout);

    getline(cin, str);
    while(str.compare("")) {
        sList.clear();
        it=sList.end();

        for(int i=0; i<str.length(); i++) {
            if(str[i]=='[')
                it=sList.begin();
            else if(str[i]==']')
                it=sList.end();
            else {
                if(it==sList.end()) cout<<"X";
                sList.insert(it, str[i]);
                if(it!=sList.end()) cout<<"Y:"<<*it;
            }
        }

        for(it=sList.begin(); it!=sList.end(); it++)
            cout<<*it;

        cout<<endl;
        getline(cin, str);
    }
}
