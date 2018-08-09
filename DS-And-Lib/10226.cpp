#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string, int> mapTree;
int tTree;
double pTree;
string str;

int main() {
    int t;

    freopen("testCase.txt", "r", stdin);

    cin>>t; getline(cin, str); // for [number] \n
    getline(cin, str); // for blank line

    while(t--) {
        mapTree.clear();
        tTree=0;

        getline(cin, str);
        while(str.compare("")) {
            mapTree[str]=mapTree[str]+1;
            tTree++;
            getline(cin, str);
        }

        for(map<string, int>::iterator it=mapTree.begin(); it!=mapTree.end(); it++) {
            pTree=(double)((*it).second)/tTree*100.0;
            printf("%s %0.4f\n",(it->first).c_str(), pTree);
        }

        if(t) cout<<endl;
    }
}
