#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;


int main() {
	int n, m;
	vector<int> dragons, knights;
	while (cin >> n >> m) {
		if (!n && !m) break;
		dragons.resize(n);
		knights.resize(m);
		for (int i = 0; i < n; ++i) cin >> dragons[i];
		for (int i = 0; i < m; ++i) cin >> knights[i];
		if (m < n) {
			cout << "Loowater is doomed!" << endl;
			continue;
		}
		sort(dragons.begin(), dragons.end());
		sort(knights.begin(), knights.end());
		int total_val = 0;
		int knight_index = 0;
		int dragon_index;
		for (dragon_index = 0; dragon_index < n && knight_index < m; ) {
			if (knights[knight_index] >= dragons[dragon_index]) {
				total_val += knights[knight_index];
				++dragon_index;
			}
			++knight_index;
		}
		if (dragon_index != n) {
			cout << "Loowater is doomed!" << endl;
		}
		else {
			cout << total_val << endl;
		}
	}
	return 0;
}