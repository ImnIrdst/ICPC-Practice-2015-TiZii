#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = 2 * acos(0);

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int cs, rings, circs;
		cin >> cs >> circs >> rings;
		double sinn = sin(PI / (double)circs);
		double coss = cos(PI / (double)circs);
		double r1 = sinn / (1. - sinn); // radius of cur circle
		double d1 = 1. + r1;            // distance to cur circle
		for (int i = 1; i < rings; i++){
			double d2 = (d1*coss + r1*sinn + sqrt(r1*r1 + 2 * r1*d1*coss*sinn))/(coss*coss);
			double r2 = d2 * sinn; // d2 = distance to next circle, r2 = radius of next circle
			d1 = d2; r1 = r2;
		}
		double diameter = 2 * PI*r1 + 2 * r1*circs;
		printf("%d %.3lf %.3lf\n", cs, r1, diameter);
	}
}