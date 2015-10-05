#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; vi vis;

// bipartate graph coloring
bool color(int u, int col){
	if (vis[u] != -1 && vis[u] != col) return false; 
	if (vis[u] != -1 && vis[u] == col) return true;
	
	vis[u] = col; bool ok = true; 
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i]; ok &= color(v, 1 - col);
	}
	return ok;
}

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n, m; cin >> n;
		
		int u, v; adj.assign(n, vi());
		for (int u = 0; u < n; u++){
			cin >> m; while (m--){
				cin >> v; 
				if (v>n) continue;
				adj[u].push_back(v - 1);
				adj[v - 1].push_back(u);
			}
		}
		int ans = 0;
		bool ok = true;
		vis.assign(n, -1);
		for (u = 0; u < n; u++){
			if (vis[u] != -1) continue;
			ok = color(u, 0); 
			if (ok == true){
				int ones = 0, zeros = 0;
				for (v = 0; v < n; v++){
					if (vis[v] == 1) ones++, vis[v] = 3;
					if (vis[v] == 0) zeros++, vis[v] = 3;
				}
				ans += max(ones, zeros);
			}
			else{
				for (v = 0; v < n; v++){
					if (vis[v] == 1) vis[v] = 3;
					if (vis[v] == 0) vis[v] = 3;
				}
			}
		}
		cout << ans << endl;
	}
}
