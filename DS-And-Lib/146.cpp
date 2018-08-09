#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);

    cin>>str;
    while(str.compare("#")) {
        if(next_permutation(str.begin(), str.end()))
            cout<<str<<endl;
        else
            cout<<"No Successor"<<endl;
        cin>>str;
    }
}
