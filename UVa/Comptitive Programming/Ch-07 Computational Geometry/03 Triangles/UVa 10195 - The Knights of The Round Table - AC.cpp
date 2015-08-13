#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double a, b, c;
	while(cin >> a >> b >> c){
		double s = (a+b+c)/2+1e-8;
		double A = sqrt(s*(s-a)*(s-b)*(s-c));
		printf("The radius of the round table is: %.3lf\n", A/s);
	}
}