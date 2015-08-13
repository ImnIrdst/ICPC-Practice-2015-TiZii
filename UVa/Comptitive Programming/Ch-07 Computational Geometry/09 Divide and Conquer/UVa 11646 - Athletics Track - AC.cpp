#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define  EPS (1e-11)

using namespace std;

int main(){
	double a, b; char c; int t=1;
	while(cin >> a >> c >> b){
		//cout << a << c << b;
		double lo=0, hi=400;
		while(fabs(lo-hi)>EPS){
			double L = (lo+hi)/2;
			double W = (b/a) * L;
			double A = (400-2*L)/2.0; // Expected Arc
			double H = (L/2.0), B = (W/2.0);
			double R = (sqrt(H*H + B*B));
			double a = (2*atan2(B,H)*R); // real Arc
			//cout << L << " **1** " << W << endl;
			//cout << L << " " << W << endl;
			//cout << a << " **2** " << A << endl;
			//cout << endl;
			if(a<A) lo = L; else hi = L; 
		}
		double L = (lo+hi)/2;
		double W = (b/a) * L;
		printf("Case %d: %.10lf %.10lf\n", t++, L, W);
	}
}
