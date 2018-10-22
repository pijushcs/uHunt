#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/***********************************************************************************************************
 * Solution:
 * Sorting and adding morning seq:{a<b<..<m}, eve seq:{k>c>..n} gives the ans as explained in the code!
 * If this solution is incorrect, atleast once of the above sum-pairs are in wrong place.
 * Let Morning Sequence: a<b, Evening Solution Sequence: k>c, Swapping them: c<k or b>a
 *
 * Note: f(x,d): x<=d?0:(x-d)
 *
 * In our solution scenario: Let, f(a+k,d) = p and f(b+c,d) = q
 * After swapping: Let f(a+c,d) = r and f(b+k,d) = s
 *
 * Case 1:
 * If p=0 and q=0, all good!
 *
 * Case 2:
 * If p=0 and q>0 (a<b | k>c), then a+k<=d and a<d, k<d.
 * Now, if we swap c-k (a<b | c<k), since c<k, c<d and r=0, but q was >0 in our hypothesis solution.
 * Now, q=f(b+c,d)>0 since k>c, s=f(b+k,d)>f(b+c,d)>0. Thus after swapping overall loss increases.
 *
 * Case 3:
 * If p>0 and q=0 (Symmetric to earlier scenario: swap a-b)
 *
 * Case 4: (Updated in TestCpp: 11389-Case-4.jpg)
 * If p>0 and q>0 (a<b | k>c): f(a+k,d)>d and f(b+c,d)>d
 * Swaping c-k (a<b | c<k). s must be>0 as c<k, i.e f(b+c,d)>d, f(b+k,d)>f(b+c,d)>d
 * Now for f(a+c,d) to be 0, c<d and a<d and a+c<d.
 *
 * Note: a+k>d(from original), b+k>d and a+c>d
 * How much more from a-->d, (d-a). How much more is k from (d-a): (k-(d-a)) = p, i.e k=p-a+d
 *
 * As s>p, s=(k+b-d)
 * s=(p-a+d+b-d)=(p-a + b)=(p-a + q+d-c)
 * i.e s=(p+q+d-(a+c)). Since (a+c)>d, s>p+q; So, overall loss increases.
 ***********************************************************************************************************/

int main() {
    int n,d,r,val;
    long long tsum;
    vector<int> vmon, veve;

    cin>>n>>d>>r;
    while(n!=0) {
        vmon.clear();
        for(int i=0; i<n; i++) {
            cin>>val; vmon.push_back(val);
        }
        sort(vmon.begin(), vmon.end());

        veve.clear();
        for(int i=0; i<n; i++) {
            cin>>val; veve.push_back(val);
        }
        sort(veve.begin(), veve.end());

        tsum=0;
        for(int i=0; i<n; i++) {
            if(vmon[i]+veve[n-i-1]>d)
                tsum+=((vmon[i]+veve[n-i-1]-d))*r;
        }

        cout<<tsum<<endl;
        cin>>n>>d>>r;
    }
}
