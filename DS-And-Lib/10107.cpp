#include <iostream>
#include <queue>
using namespace std;

int main() {
    long long a,b=-1,n,mid;
    priority_queue<long long> maxHeap;
    priority_queue<long long, vector<long long>, greater<long long> > minHeap;

    freopen("testCase.txt", "r", stdin);
    freopen("testOut.txt", "w", stdout);
    cin>>a;
    cout<<a<<endl;

    while((cin>>n)) {
        if(b==-1){
            b=n;
            if(a>b) { minHeap.push(b); maxHeap.push(a); }
            else { maxHeap.push(b); minHeap.push(a); }
            mid = (a+b)/2;
        }
        else {
            if(n<mid) maxHeap.push(n);
            else minHeap.push(n);

            if(maxHeap.size()>minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(minHeap.size()>maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if(maxHeap.size()==minHeap.size())
                mid=(maxHeap.top()+minHeap.top())/2;
            else if(maxHeap.size()>minHeap.size())
                mid=maxHeap.top();
            else
                mid=minHeap.top();
        }

        cout<<mid<<endl;
    }
}
