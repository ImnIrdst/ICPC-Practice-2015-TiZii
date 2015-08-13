#include <iostream>
#include <cstdio>
#include <cmath>
#define PI  (2*acos(0))

using namespace std;

int main(){
	double D,V;
	while(cin >> D >> V && (D||V)){
		printf("%.3lf\n", pow((D*D*D - 6*V/PI),1.0/3.0));
	}
}