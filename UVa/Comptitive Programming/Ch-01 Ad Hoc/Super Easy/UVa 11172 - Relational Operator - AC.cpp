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
	int tc, a, b; cin >> tc;
	while(tc--){
		cin >> a >> b;
		if(a==b) cout << "=" << endl;
		if(a>b) cout << ">" << endl;
		if(a<b) cout << "<" << endl;
	}
	return 0;
}