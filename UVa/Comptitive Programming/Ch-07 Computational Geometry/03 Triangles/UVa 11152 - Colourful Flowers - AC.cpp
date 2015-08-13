#include <iostream>
#include <cmath>
#include <cstdio>
#define pi (2*acos(0))

using namespace std;

double a,b,c,A,S,r,R,ros,vio,sun;

int main(){
	while(cin >> a >> b >> c){
		S = (a + b + c) / 2;
		A = sqrt(S*(S-a)*(S-b)*(S-c));
		r = A / S;
		R = (a*b*c) / (4*A);
		ros = r*r*pi;
		vio = A - ros;
		sun = R*R*pi - A;
		printf("%.4lf %.4lf %.4lf\n",sun , vio, ros);
	}
}