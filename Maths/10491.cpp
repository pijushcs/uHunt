#include<iostream>
using namespace std;

int main() {
    double ncow, ncar, nshow;
    while((cin>>ncow)) {
        cin>>ncar>>nshow;
        double res=((ncow/(ncar+ncow))*(ncar/(ncar+ncow-nshow-1.0))) + ((ncar/(ncar+ncow))*((ncar-1)/(ncar+ncow-nshow-1.0)));
        printf("%0.5f\n", res);
    }
}
