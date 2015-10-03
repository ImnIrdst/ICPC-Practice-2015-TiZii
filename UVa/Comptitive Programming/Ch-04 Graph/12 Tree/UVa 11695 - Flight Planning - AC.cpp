#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

struct edge {
	int u, v, used;
	edge(int u = 0, int v = 0) : u(u), v(v), used(false)  {}
}removed, added, tmpadded;

int n, m; vvi adj; vi dist, par, path; vector<edge> edges;

void bfs(int s, int& furthest, int& mid) {
	queue<int> q; q.push(s);
	dist.assign(n, -1);  dist[s] = 0; 
	par.assign(n, -1); path.clear();

	int u, v;
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			v = adj[u][i];
			if (dist[v] == -1) {
				q.push(v); dist[v] = dist[u] + 1; par[v] = u;
			}
		}
	}
	v = u;
	while (v != s) {
		path.push_back(v);
		v = par[v];
	}
	path.push_back(v);

	furthest = u;
	mid = path[path.size() / 2];
}

int build_new_graph(int i) {
	adj.assign(n, vi());
	for (int j = 0; j < m; j++) {
		if (edges[j].used == false) {
			int u = edges[j].u;
			int v = edges[j].v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
	// left tree diameter
	int furthest1, mid1;
	bfs(edges[i].u, furthest1, mid1);
	bfs(furthest1, furthest1, mid1);

	// right tree diameter
	int furthest2, mid2;
	bfs(edges[i].v, furthest2, mid2);
	bfs(furthest2, furthest2, mid2);

	// new tree construction
	adj[mid1].push_back(mid2);
	adj[mid2].push_back(mid1);
	tmpadded = edge(mid1, mid2);

	// new tree diameter
	int ans, mid3;
	bfs(mid1, ans, mid3);
	bfs(ans, ans, mid3);

	return dist[ans];
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n; m = n - 1; 

		int u, v; 
		vvi adj1, adj2; 
		edges.resize(m);
		for (int i = 0; i < m; i++) {
			cin >> u >> v; u--, v--;
			edges[i] = edge(u, v);
		}

		int ans = 1e9;
		for (int i = 0; i < m; i++) {
			edges[i].used = true;
			int tmp = build_new_graph(i);
			if (tmp < ans) {
				ans = tmp; removed = edges[i]; added = tmpadded;
			}
			edges[i].used = false;
		}

		cout << ans << endl;
		cout << removed.u+1 << " " << removed.v+1 << endl;
		cout << added.u+1   << " " << added.v+1   << endl;
	}
}

