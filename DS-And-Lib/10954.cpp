#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    long long k, x, y, res;
    priority_queue<long long, vector<long long>, greater<long long> > qAdd;

    cin>>n;
    while(n) {
        res=0;
        for(int i=0; i<n; i++) {
            cin>>k;
            qAdd.push(k);
        }

        while(qAdd.size()>1) {
            x=qAdd.top(); qAdd.pop();
            y=qAdd.top(); qAdd.pop();
            res+=x+y; qAdd.push(x+y);
        }

        cout<<res<<endl; qAdd.pop();
        cin>>n;
    }
}
