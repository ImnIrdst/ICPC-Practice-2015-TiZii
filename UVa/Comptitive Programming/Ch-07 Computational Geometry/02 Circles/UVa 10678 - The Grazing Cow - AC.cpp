#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		double rope, dist; cin >> dist >> rope;
		
		double a = rope/2;
		double b = sqrt(a*a - (dist/2)*(dist/2));
		printf("%.3lf\n", 2*acos(0)*a*b);
	}
}