#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
	
	int x, y, z; 
	vector<int> cmp; Block() {}
	Block(int x, int y, int z)
		:x(x), y(y), z(z) {
		cmp.push_back(x); cmp.push_back(y); cmp.push_back(z);
	}
	bool operator<(const Block op) const {
		for (int i = 0; i < 3; i++) {
			if (cmp[i] < op.cmp[i]) return 0;
			if (cmp[i] > op.cmp[i]) return 1;
		}
		return 0;
	}
}; vector<Block> b;

int main() {
	int n, cs = 1;
	while (cin >> n && n) {
		int x, y, z; b.clear();
		for (int i = 0; i < n; i++) {		
			cin >> x >> y >> z;
			b.push_back(Block(x, y, z)); b.push_back(Block(x, z, y));
			b.push_back(Block(y, x, z)); b.push_back(Block(y, z, x));
			b.push_back(Block(z, y, x)); b.push_back(Block(z, x, y));
		}
		int ans = 0;
		sort(b.begin(), b.end());
		vector<int> dp(b.size(), 0);
		for (int i = 0; i < b.size(); i++){
			dp[i] = b[i].z;
			for (int j = 0; j < i; j++) {
				if (b[i].x < b[j].x && b[i].y < b[j].y) {
					dp[i] = max(dp[i], dp[j] + b[i].z);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << "Case " << cs++ << ": ";
		cout << "maximum height = " << ans << endl;
	}
}