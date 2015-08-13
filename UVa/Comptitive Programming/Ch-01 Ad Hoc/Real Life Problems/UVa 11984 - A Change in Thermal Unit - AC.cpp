#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while( tc-- ){
		double C, d; cin >> C >> d;

		double Fc = (9.0*C)/5.0 + 32;
		double Fd = Fc + d;
		double Cd = ((Fd-32)*5)/9.0;

		printf("Case %d: %.2lf\n", cs++, Cd);
	}
}