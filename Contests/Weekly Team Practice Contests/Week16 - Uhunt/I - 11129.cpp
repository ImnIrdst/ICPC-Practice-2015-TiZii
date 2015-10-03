#include <iostream>
#include <vector>

using namespace std;

vector<int> tmp, ans; int n;

void solve(int left, int right) {
	tmp = ans; 
	if (right - left <= 1) return;
	
	int pos = left;
	for (int i = left; i <= right; i += 2) 
		ans[pos++] = tmp[i];
	for (int i = left+1; i <= right; i += 2) 
		ans[pos++] = tmp[i];
	
	int mid = (left + right) / 2;
	solve(left, mid); solve(mid + 1, right);
}

int main() {
	while (cin >> n) {
		ans.clear();
		for (int i = 0; i < n; i++) {
			ans.push_back(i);
		}

		solve(0, n - 1);

		cout << n << ":";
		for (int i = 0; i < n; i++) cout  << " " << ans[i]; cout << endl;
	}
}