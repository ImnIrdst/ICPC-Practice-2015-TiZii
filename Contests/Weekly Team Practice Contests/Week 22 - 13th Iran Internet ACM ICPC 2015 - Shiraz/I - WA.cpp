#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adjOrg, adjRev, adjSCC;  vi vis, ord, col, siz;

void dfsOrg(int u) {
	if (vis[u]) return; vis[u] = true;
	for (int i = 0; i < adjOrg[u].size(); i++) {
		dfsOrg(adjOrg[u][i]);
	}
	ord.push_back(u);
}

int dfsRev(int u, int color) {
	if (col[u]) return 0; col[u] = color;

	int ret = 1;
	for (int i = 0; i < adjRev[u].size(); i++) {
		ret += dfsRev(adjRev[u][i], color);
	}
	return ret;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		int m; cin >> m;
		adjOrg.assign(n, vi());
		adjRev.assign(n, vi());

		for (int i = 0; i < m; i++) {
			int u; cin >> u; u--;
			int v; cin >> v; v--;
			
			adjOrg[u].push_back(v);
			adjRev[v].push_back(u);
		}

		ord.clear();
		vis.assign(n, 0);
		for (int u = 0; u < n; u++) {
			if (!vis[u]) dfsOrg(u);
		}

		int color = 0;
		col.assign(n, 0);
		siz.assign(n, 0);
		while (!ord.empty()) {
			int u = ord.back();
			if (!col[u]) {
				int size = dfsRev(u, color); // SCC Size
				siz[color++] = size;
			}
			ord.pop_back();
		}
		adjSCC.assign(color, vi());
		for (int u = 0; u < n; u++) {
			for (int i = 0; i < adjOrg[u].size(); i++) {
				int v = adjOrg[u][i];
				adjSCC[col[u]].push_back(col[v]);
			}
		}


	}
}