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
		int n,a , mn=INF, mx=(-1)*INF;
		cin >> n;
		while(n--){
			cin >> a;
			mn=min(mn,a);
			mx=max(mx,a);
		}
		cout << (mx-mn)*2 << endl;
	}
	return 0;
}