#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define leftCh(i) (i*2+1)
#define rightCh(i) (i*2+2)

using namespace std;

const int MAX = ((1 << 20) + 10);

int tree[MAX], dp[MAX][20], h, k, n;

int solve(int node, int rem) {
	if (node >= n) return -1e9;
	if (rem  <= 0) return -1e9;

	int& dpp = dp[node][rem];// [picked];
	if (dpp != -1) return dpp;

	dpp = tree[node];
	for (int r = 1; r < rem; r++) {
		dpp = max(dpp,
			solve(leftCh(node), r) +
			solve(rightCh(node), rem - r));
	}

	return dpp;

}

void buildTree(int node) {
	if (node >= n) return;
	scanf("%d", &tree[node]);
	buildTree(leftCh(node));
	buildTree(rightCh(node));
}


int main() {
	// Test for testcase 0
	while (cin >> h && h != -1) {
		cin >> k;
		n = (1 << (h + 1)) - 1;
		buildTree(0); 
		
		memset(dp, -1, sizeof dp);
		cout << solve(0, k) << endl;
	}
}