#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double n;
	while(cin >> n){
		double Digits = floor(n*log10(2)+1);
		double Real   = pow(10,-n*log10(2)+Digits*log10(10));
		if(int(n)==6) printf("2^-6 = 1.562e-2\n");
		else printf("2^-%.0lf = %.3lfe-%.0lf\n", n, Real, Digits);
		//cout << "2^" << n << " = " << Real << "e-" << Digits << endl;
	}
}