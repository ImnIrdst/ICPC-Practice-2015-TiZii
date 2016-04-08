#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long int64;

const int MAX = 1e7;

map<int64, int64> dp;

int64 calcLen(int64 n){
	if (dp.count(n)) return dp[n];
	int t = n;
	if (n % 2 == 0) n /= 2;
	else if (n % 2 == 1) n = 3 * n + 1;

	int64 ret = 1;
	while( n!=1 ){ ret++;
		if (n % 2 == 0) n /= 2;
		else if (n % 2 == 1) n = 3 * n + 1;
	}
	return dp[t] = ret;
}

int main(){
	int64 n, m;
	while (cin >> n >> m && (n||m)){
		if (n > m) swap(n, m);
		int64 ansId = -1, ansVal = -1;
		for (int i = n; i <= m; i++){
			int64 len = calcLen(i);
			if (len > ansVal) ansVal = len, ansId = i;
		}

		cout << "Between " << n << " and " << m << ", " << ansId << " ";
		cout << "generates the longest sequence of " << ansVal << " values.";
		cout << endl;
	}
}