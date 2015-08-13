#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		n*=567; n/=9; n+=7492; n*=235; n/=47; n-=498; 
		n/=10; n=(n>0 ? n : -1*n); n%=10;
		cout << n << endl;
	}
	return 0;
}