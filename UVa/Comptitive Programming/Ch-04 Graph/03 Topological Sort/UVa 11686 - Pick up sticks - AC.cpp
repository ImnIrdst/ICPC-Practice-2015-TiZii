#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; vi vis; stack<int> ord;

void toposort(int u){
	if (vis[u]) return; vis[u] = 1;

	for (int i = 0; i < adj[u].size(); i++){
		toposort(adj[u][i]);
	}

	ord.push(u);
}

int main(){
	int n, m;
	while (cin >> n >> m && (n || m)){
		adj.assign(n, vi());
		int u, v;
		for (int i = 0; i < m; i++){
			cin >> u >> v; u--, v--;
			adj[u].push_back(v);
		}
		vis.assign(n, 0);
		for (u = 0; u < n; u++){
			if (!vis[u]) toposort(u);
		}

		vi out; 
		vis.assign(n, 0);
		bool impos = false;
		while (!ord.empty()){
			u = ord.top(); ord.pop(); 
			out.push_back(u); vis[u] = true;
			for (int i = 0; i < adj[u].size(); i++){
				v = adj[u][i];
				if (vis[v]) 
					impos = true;
			}
		}

		if (impos){
			cout << "IMPOSSIBLE" << endl; continue;
		}
		else {
			for (int i = 0; i < n; i++){
				cout << out[i]+1 << endl;
			}
		}
	}
}