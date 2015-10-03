#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int bug[20 + 10], date[20 + 10];


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		queue<int> q; int p;
		int freq[10] = { 0 };
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> p; freq[p]++;
			if (i != m) q.push( p);
			if (i == m) q.push(-p);
		}

		int ans = 1;
		while (true) {
			int a = q.front(); q.pop();

			bool hasHigher = false;
			for (int i = abs(a) + 1; i < 10; i++) {
				if (freq[i] > 0) hasHigher = true;
			}

			
			if (hasHigher == false && a < 0) break;
			if (hasHigher == true) q.push(a); else freq[abs(a)]--, ans++;
		}

		cout << ans << endl;
	}
}