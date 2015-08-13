#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = 2*acos(0);

int main(){
	double r, n;
	while(cin >> r >> n){
		double ang1 = (2*pi)/n;
		double ang2 = (pi - ang1)/2;

		double side = (r * sin(ang1)) / sin(ang2);
		double h    = sqrt(r*r-(side*side)/4);
		double area = (h*side)/2;

		printf("%.3lf\n", area*n);
	}
}