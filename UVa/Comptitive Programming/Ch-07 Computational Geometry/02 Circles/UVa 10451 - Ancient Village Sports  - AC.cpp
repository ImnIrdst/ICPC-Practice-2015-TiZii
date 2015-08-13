#include <iostream>
#include <cmath>
#include <cstdio>


using namespace std;

const double INF = 1e100;
const double EPS = 1e-12;
const double PII = 2*acos(0);

int main(){
	int n, t=1; double A; //cout << PII << endl;
	while(cin >> n >> A && n>=3){
		double r = sqrt( ( cos(PII/n)/sin(PII/n) ) * (A/n));
		double R = r / cos(PII/n);
		
		printf("Case %d: ", t++ );
		printf("%.5lf " , PII*R*R - A);
		printf("%.5lf\n", A - PII*r*r);
	}
}
