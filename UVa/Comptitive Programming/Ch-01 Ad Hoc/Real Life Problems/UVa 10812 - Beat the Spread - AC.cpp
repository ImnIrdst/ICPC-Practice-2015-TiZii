#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <set>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int sum, def;
		cin >> sum >> def;
		int score=sum-def;
		if( (sum-def)%2 && (sum-def)<0) cout << "impossible" << endl;
		else cout << sum-score/2 << " " << score/2 << endl;
	}
	return 0;
}