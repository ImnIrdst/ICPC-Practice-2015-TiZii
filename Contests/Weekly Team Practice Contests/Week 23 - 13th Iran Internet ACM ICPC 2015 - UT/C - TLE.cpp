#include <iostream>
#include <string.h>

using namespace std;

typedef long long int64;

int64 dp[45][810][810], x[45], y[45], n;

int64 solve(int id, int sumx, int sumy) {
	if (id >= n && sumx == 400 && sumy == 400) return 1;
	else if(id >= n) return 0;

	int64& dpp = dp[id][sumx][sumy];
	if (dpp != -1) return dpp;

	dpp = solve(id + 1, sumx + x[id], sumy + y[id])
		+ solve(id + 1, sumx, sumy);

	return dpp;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n; // TODO: n == 0
		if (n == 0) {
			cout << 0 << endl; continue;
		}
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i]; //x[i] += 400; y[i] += 400;
		}
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0+400, 0+400) - 1 << endl;
	}
}