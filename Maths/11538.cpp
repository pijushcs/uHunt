#include<iostream>
using namespace std;

long long sqSum(long long n) {
    return n*(n+1)*(2*n+1)/6;
}

long long sumx(long long n) {
    return n*(n+1)/2;
}

long long findQueens(long long m, long long n) {
    long long ares=0;

    // ways of placing two queens on first row: n*(n-1)
    // total ways for all rows: m*(n*(n-1))
    ares+=m*(n*(n-1));

    // Similarly for attack on columns
    ares+=n*(m*(m-1));

    long long smin=min(m,n);
    long long smax=max(m,n);

    // Attack on diagnoals: The diag length increases from {1,2..smin}
    // and then remain smin for (smax-smin-1) times and then again decreases from {smin...1}
    // Now, no of ways of placing queens on diagonals upto n: 2*1(for second diag) + 3*2 + 4*3 + 5*3 + .. n(n-1)
    // Note that n*(n-1) = (n^2 - n) and the series can be broken to 1^1-1 + 2^2-2 + 3^3-3 + ... + n^2-n = sqSum(n)-sum(n)

    long long diagRes=sqSum(smin)-sumx(smin) // for increasing part
                    + (smax-smin-1)*smin*(smin-1) // for same part
                    + sqSum(smin)-sumx(smin);  // for decreasing part

    ares+=2*diagRes; // Since diagonals start from both left and right

    return ares;
}

int main() {
    long long m, n;

    cin>>m>>n;
    while(m!=0 && n!=0) {
        cout<<findQueens(m,n)<<endl;
        cin>>m>>n;
    }
}
