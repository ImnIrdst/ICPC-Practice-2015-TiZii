#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

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

struct edge {
	int u, v, w;
	edge(int u = 0, int v = 0, int w = 0) :u(u), v(v), w(w) {};
	bool operator<(const edge& b) const {
		if (w == b.w && v == b.w) return u < b.u;
		if (w == b.w) return v < b.v; return w < b.w;
	}
};

int n, m, bit; vector<edge> e;

int Kruskal(int bit, int which) {
	DisJointSet djst(n); 
	 int ans = 0; int j = 0;
	for (int i = 0; i<e.size() ; i++) {
		if ((bit&(1 << i) && which == 1) || (!(bit&(1 << i)) && which == 0)) 
		if (djst.Find(e[i].u) != djst.Find(e[i].v)) {
			djst.Uni(e[i].u, e[i].v); ans += e[i].w; j++;
		}
	}
	return ans;
}

vvi adj; vi vis;

void bfs(int u) {
	if (vis[u]) return; vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		if(!vis[adj[u][i]]) bfs(adj[u][i]);
	}
}

int solve(int bit) {
	adj.assign(n, vi()); vis.assign(n, 0);
	for (int i = 0; i < m; i++) {
		if (bit&(1 << i)) {
			adj[e[i].u].push_back(e[i].v);
			adj[e[i].v].push_back(e[i].u);
		}
	}
	bfs(0);
	for (int i = 0; i < n; i++)
		if (vis[i] == 0) return 1e6;
	
	adj.assign(n, vi()); vis.assign(n, 0);
	for (int i = 0; i < m; i++) {
		if (!(bit&(1 << i))) {
			adj[e[i].u].push_back(e[i].v);
			adj[e[i].v].push_back(e[i].u);
		}
	}
	bfs(0);
	for (int i = 0; i < n; i++)
		if (vis[i] == 0) return 1e6;

	int ans = 0;
	
	ans += Kruskal(bit, 0);
	ans += Kruskal(bit, 1);

	return ans;
}


int ans;

int itrs = 1e6;

void backtrack(int id, int cnt, int bit) {
	if (itrs-- < 0) return;
	if (cnt == n-1 ) { // TODO if tedad 1kash > m-1
		ans = min(ans, solve(bit)); return;
	}
	if (cnt + (m - id) < n - 1 || cnt>n-1) return;
	for (int i = id; i < m; i++) {
		backtrack(i + 1, cnt+1, bit | (1 << i));
	}
}


int main() {
	while (cin >> n && n) {
		cin >> m; itrs = 1e6/2;
		e.resize(m); ans = 1e9;
		for (int i = 0; i < m; i++) {
			cin >> e[i].u >> e[i].v >> e[i].w;
			e[i].u--; e[i].v--;
		}
		sort(e.begin(), e.end());
		backtrack(0, 0, 0);
		if (ans == 1e6) cout << "No way!" << endl;
		else			cout << ans << endl;
	}
}
