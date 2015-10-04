#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long int64;
const int MAXREM = 300 + 10;
const int MAXCNT = 300 + 10;
const int MAXCUR = 300 + 10;

int64 dp[MAXCUR][MAXREM][MAXCNT], n;

int64 solve(int cur, int rem, int cnt) {
	if (rem == 0 && cnt == 0) return 1;
	if (cur >  n || rem <= 0 || cnt <= 0 || cnt > n) return 0;
	
	int64& dpp = dp[cur][rem][cnt];
	if (dpp != -1) return dpp;

	dpp = solve(cur, rem - cur, cnt - 1) + solve(cur + 1, rem, cnt);
	return dpp;
}

int main() {
	int l1, l2; string line;
	memset(dp, -1, sizeof dp);
	while (getline(cin, line)) {
		stringstream sstr(line);
		
		int ii = 0 , in[3];
		while (sstr >> in[ii]) ii++;
		
		n = in[0];
		if (ii == 1) l1 = 1, l2 = n;
		if (ii == 2) l1 = 1, l2 = in[1];
		if (ii == 3) l1 = in[1], l2 = in[2];
		if (n == 0 && (l1 == 0 || l1 == 1) && l2 == 0) {
			cout << 1 << endl; continue;
		}
		int64 ans = 0; 
		l1 = min(MAXCNT-1, l1); 
		l2 = min(MAXCNT-1, l2);
		for (int cnt = l1; cnt <= l2; cnt++) {
			ans += solve(1, n, cnt);
		}

		cout << ans << endl;
	}
}

