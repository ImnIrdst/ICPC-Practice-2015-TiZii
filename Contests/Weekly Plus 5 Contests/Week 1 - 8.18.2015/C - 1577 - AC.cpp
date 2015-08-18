#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;

bool check(vector<int>& batt, int d) {
	vector<int> pick;
	vector<bool> used(batt.size(), false);

	
	if (batt[1] - batt[0] > d) return false;
	pick.push_back(batt[0]); used[0] = true;
	pick.push_back(batt[1]); used[1] = true;

	int pickCnt = 1;
	for (int i = 3; pickCnt < n && i<batt.size()  ; i++) {
		if (batt[i] - batt[i - 1] <= d && !used[i] && !used[i-1]) {
			pick.push_back(batt[i]);	used[i] = true;
			pick.push_back(batt[i-1]);	used[i - 1] = true;
			pickCnt++;
		}
	}
	if (pickCnt != n) return false;

	int head = 0, cap = k-1;
	for (int i = 0; i<batt.size(); i++) {
		if (!cap) head++, cap = k-1;
		if (!used[i]) {
			if (batt[i] < pick[head]) return false;
			else used[i] = true, cap--;
		}
	}
	return true;
}

int main() {
	
	while (cin >> n >> k) {
		vector<int> batt(n*2*k); // battery
		for (int i = 0; i < 2 * n*k; i++) {
			cin >> batt[i];
		}

		sort(batt.begin(), batt.end());

		int lo = 0, hi = 1e9;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (check(batt, mid)) hi = mid; else lo = mid + 1;
		}
		cout << hi << endl;
	}
}