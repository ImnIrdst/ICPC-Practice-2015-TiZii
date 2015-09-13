#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct DisJointSet {
	vector<int> par, rnk, cnt; int numOfsets;

	DisJointSet(int n) {
		par.assign(n, -1); rnk.assign(n, 0); cnt.assign(n, 1); //par==parent
		numOfsets = n; // if we wanna count number of disjoint sets
	}

	int Find(int a) {
		int i = a, j = a, tmp;
		while (par[i] != -1) { i = par[i]; }
		while (par[j] != -1) { tmp = par[j]; par[j] = i; j = tmp; } //path compression
		return i;
	}
	int Uni(int a, int b) {
		int A = Find(a), B = Find(b);
		if (A != B) {
			if (rnk[A]<rnk[B]) swap(A, B); // union using rank
			if (rnk[A] == rnk[B]) rnk[A]++;
			par[B] = A;
			cnt[A] += cnt[B]; // if we wanna count each set size
			numOfsets--; // if we wanna count number of disjoint sets
		}
		return cnt[A]; // if we wanna count each set size
	}
};

int main() {
	int n, m;
	while (cin >> n >> m && (n||m)) {
		DisJointSet djs(n);
		for (int i = 0; i < m; i++) {
			int k; cin >> k;
			if (k < 1)  continue;
			int u,v; cin >> u;
			for (int j = 1; j < k ; j++) {
				cin >> v; djs.Uni(u, v);
			}
		}

		int ans = 0;
		int group = djs.Find(0);
		for (int i = 0; i < n; i++) {
			if (group == djs.Find(i)) ans++;
		}

		cout << ans << endl;
	}
}