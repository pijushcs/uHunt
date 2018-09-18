#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> res;

void printSol(long long cprice, long long csum, long long cprod, int k) {
    if(k==4) {
        if(cprod==1000000) return;

        long long dres=(csum*1000000)/(cprod-1000000);
        if(dres<=0 || dres>=2000 || dres<res[2]) return;
        if(csum+dres>2000 || dres<=0) return;

        if(cprod*dres==(csum+dres)*1000000)
            printf("%0.2f %0.2f %0.2f %0.2f\n", res[0]/100.00, res[1]/100.00, res[2]/100.00, dres/100.00);

        return;
    }

    while(cprice+csum<=2000) {
        res.push_back(cprice);
        printSol(cprice, csum+cprice, cprod*cprice, k+1);
        res.pop_back();

        cprice+=1;
        if(k==1 && (cprod*cprice)>2000) return;
        if(k==2 && (cprod*cprice)>200000) return;
        if(k==3 && (cprod*cprice)>20000000) return;
    }
}

int main() {
    freopen("testOut.txt", "w", stdout);
    printSol(1, 0, 1, 1);
}
