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

int a[3];

int main(){
	int tc, t=1; cin >> tc;
	while(tc--){
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3); 
		printf("Case %d: %d\n", t++, a[1]);
	}
	return 0;
}