#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int64;

int main() {
	int64 k;
	while (cin >> k && k) {
		int64 m;
		vector<int64> ans; 
		for (int64 a0 = 0; a0 <= 9; a0++) {
			if ((k - a0) % 9 == 0) {
				m = (k - a0) / 9;
				ans.push_back(m * 10 + a0);
			}
		}

		sort(ans.begin(), ans.end());

		cout << ans[0];
		for (int i = 1; i < ans.size(); i++) {
			cout << " " << ans[i];
		}cout << endl;
	}
}