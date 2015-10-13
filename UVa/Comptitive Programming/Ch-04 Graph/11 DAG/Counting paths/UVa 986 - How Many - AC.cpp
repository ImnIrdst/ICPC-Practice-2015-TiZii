#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100 + 10;

int dp[20*2+10][1000][20+10][2], n, r, k;

int solve(int x, int y, int peaks, int isDown){
	if (x  > 2 * n || y < 0   || peaks > r) return 0;
	if (x == 2 * n && (y != 0 || peaks != r)) return 0;
	if (x == 2 * n && (y == 0 && peaks == r)) 
		return 1;

	int& dpp = dp[x][y][peaks][isDown];
	if (dpp != -1) return dpp;

	dpp  = 0;
	dpp += solve(x + 1, y + 1, peaks, 0);
	dpp += solve(x + 1, y - 1, peaks + (y == k && !isDown), 1);
	return dpp;
}

int main(){
	while (cin >> n >> r >> k){
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0, 0, 0) << endl;
	}
}