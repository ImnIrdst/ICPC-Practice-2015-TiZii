#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 5000 + 10;

typedef vector<int> vi;
typedef vector<vi > vvi; vvi adj;

int dist[MAX], n, Minh, Maxh, furthest;

void dfs(int u, int par, int h){
	dist[u]=max(h, dist[u]);
	if(dist[u] > Maxh)
		Maxh = dist[u], furthest = u;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v  = adj[u][i];
		if( v != par ) dfs(v, u, h+1);
	}
}

int main(){
	while(cin >> n){
		adj.assign(n, vi());
		for(int u=0 ; u<n ; u++){
			int m, v; cin >> m;
			for(int i=0 ; i<m ; i++){
				cin >> v; adj[u].push_back(v-1);
			}
		}
		memset(dist,0,sizeof dist);
		// find the maximum distance of each node from furthest node
		furthest = 0; Minh=1e9, Maxh=0;
		dfs(furthest, -1, -1); dfs(furthest, -1, -1); dfs(furthest, -1, -1);

		
		for(int u=0 ; u<n ; u++){
			Minh = min(Minh, dist[u]);
		}

		cout << "Best Roots  :";
		for(int u=0 ; u<n ; u++) 
			if(dist[u]==Minh) cout << " " << u+1; cout << endl;
		cout << "Worst Roots :";
		for(int u=0 ; u<n ; u++) 
			if(dist[u]==Maxh) cout << " " << u+1; cout << endl;
	}
}
