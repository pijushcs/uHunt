#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef pair<int, int> ii;

vector<ii> vcord;
vector<vector<int> > rPath;
vector<vector<double> > dP;

int mpow;

double distx(int a, int b) {
    return sqrt((vcord[a].first-vcord[b].first)*(vcord[a].first-vcord[b].first) +
                   (vcord[a].second-vcord[b].second)*(vcord[a].second-vcord[b].second)) + 16.0;
}

double findCon(int pos, int mask) {
    double minNow = 1000000.0;
    if(mask==(mpow-1)) return 0;

    if(dP[pos][mask]!=-1) return dP[pos][mask];

    for(int i=0; i<vcord.size(); i++) {
        if((mask&(1<<i))==0) {
            mask=mask|(1<<i);
            double res=findCon(i, mask);
            mask=mask^(1<<i);

            if(res+distx(pos, i)<minNow) {
                minNow = res+distx(pos, i);
                rPath[pos][mask]=i;
            }
        }
    }

    dP[pos][mask] = minNow;
    return minNow;
}

double minCon() {
    int mask=0, mpos, pos;
    double minNow = 1000000.0;

    int i=0;
    for(int i=0; i<vcord.size(); i++) {
        mask=mask|(1<<i);
        double res = findCon(i, mask);

        if(minNow>res) {
            minNow=res;
            mpos=i;
        }

        mask=mask^(1<<i);
    }

    for(int i=0; i<vcord.size()-1; i++) {
        mask=mask|(1<<mpos);
        pos = rPath[mpos][mask];

        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2f feet.\n", vcord[mpos].first, vcord[mpos].second,
                vcord[pos].first, vcord[pos].second, distx(mpos, pos));

        mpos=pos;
    }

    return minNow;
}

int main() {
    int n,x,y, tcase=1;

    cin>>n;
    while(n!=0) {
        mpow = pow(2, n);
        dP.assign(n, vector<double>());
        rPath.assign(n, vector<int>());
        vcord.clear();

        for(int i=0; i<n; i++) {
            cin>>x>>y;
            rPath[i].assign(mpow, -1);
            dP[i].assign(mpow, -1);

            vcord.push_back(ii(x,y));
        }

        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<tcase++<<endl;

        double res=minCon();
        printf("Number of feet of cable required is %0.2f.\n", res);

        cin>>n;
    }
}
