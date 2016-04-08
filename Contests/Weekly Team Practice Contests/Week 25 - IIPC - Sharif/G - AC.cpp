#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;

typedef long long int64;

int64 dp[32];

int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int N, m, k;
		cin >> N >> m >> k;
		memset(dp, 0, sizeof dp);
		for (int n = 1; n <= N; ++n) {
			if (n < m) {
				if (n != m) {
					dp[n] = 1 << (n - 1);
				}
				else {
					dp[n] = max(0, (1 << (n - 1) - 1));
				}
			}
			else {
				for (int i = 1; i < n; ++i) {
					if (i%k != m) {
						dp[n] += dp[n - i];
					}
				}

				if (n%k != m) {
					dp[n] += 1;
				}
			}
		}
		cout << dp[N] << endl;
	}
	return 0;
}