#include <iostream>
#include <stdio.h>
#include <cmath>
#define int64 long long
using namespace std;

int64 gcd(int64 a, int64 b){if(b==0) return a; return gcd(b,a%b); }

int main(){
	int64 a, b, first;
	while(cin >> first && first){
		a=first-first;
		while(cin >> b && b){
			b-=first;
			a=gcd(a,b);
		}
		cout << abs(a) << endl;
	}
	return 0;
}
