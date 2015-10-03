#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;
const int MAXK = 1e2 + 10;

int seq[MAXN], freq[MAXK], cs=1;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k; cin >> n >> m >> k;
		seq[1] = 1; seq[2] = 2; seq[3] = 3;
		for (int i = 4; i <= n; i++) {
			seq[i] = (seq[i - 1] + seq[i - 2] + seq[i - 3]) % m + 1;
		}
		memset(freq, 0, sizeof freq);

		int cnt = 0, jj=-1;
		for (int j = 1; j <=n ; j++) {
			if (seq[j] <= k && !freq[seq[j]])
				freq[seq[j]]++, cnt++;// , jj = j;
			else if (seq[j] <= k && freq[seq[j]]) freq[seq[j]]++;
			if (cnt == k) {
				jj = j; break;
			}
		}
		if (jj == -1) {
			printf("Case %d: sequence nai\n", cs++); continue; 
		}

		int ans = jj;
		for (int i = 1, j = jj; j <= n; j++) {
			if (seq[j] <= k && j!=jj ) freq[seq[j]]++;
			while (seq[i] > k || freq[seq[i]] > 1) {
				if (seq[i] <= k && freq[seq[i]] > 1) freq[seq[i]]--;
				i++;
			}
			ans = min(ans, j - i + 1);
		}
		printf("Case %d: %d\n", cs++, ans);
	}
}