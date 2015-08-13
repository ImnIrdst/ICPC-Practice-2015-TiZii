#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#define int64 long long
#define MAX (100+10)

using namespace std;

int64 gcd(int64 a, int64 b){if(b==0) return a; return gcd(b,a%b); }

int64 a[MAX],n;

int main(){
	int tc; cin >> tc; cin.ignore(); string str;
	while(tc--){
		getline(cin,str); stringstream sstr(str);
		for(n=0 ; sstr >> a[n] ; n++);

		int64 Max=-1;
		for(int i=0 ; i<n ;i++){
			for(int j=i+1 ; j<n ; j++){
				Max=max(Max,gcd(a[i],a[j]));
			}
		}

		printf("%lld\n", Max);
	}
	return 0;
}
