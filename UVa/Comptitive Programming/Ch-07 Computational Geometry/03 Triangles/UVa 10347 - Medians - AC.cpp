#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double a, b, c;
	while(cin >> a >> b >> c){
		double s = (a+b+c)/2;
		double A = sqrt(s*(s-a)*(s-b)*(s-c));
		if(A>0){
			printf("%.3lf\n", 4.0/3.0*A);
			
		}
		else{
			printf("%.3lf\n", -1.0);
		}
	}
}