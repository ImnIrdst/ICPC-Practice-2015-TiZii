#include <iostream>
#include <vector>

using namespace std;

typedef vector< int>  vi;
typedef vector< vi > vvi;

int n, m; vvi adj; vi vis, stk;

void dfs(int u){
	if(vis[u]) return; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);	
	}
	stk.push_back(u);	
}

int main(){
	int tc, cs=1; cin >> tc;
	while(tc--){
		cin >> n >> m; adj.assign(n,vi()); 
		
		int u, v; 
		for(int i=0 ; i<m ; i++){
			cin >> u >> v; u--, v--;
			adj[u].push_back(v);
		}
		
		vis.assign(n,0); stk.clear();
		for(int u=0 ; u<n ; u++){
			if(!vis[u]) dfs(u);	
		}
		
		int ans=0;
		vis.assign(n,0); 
		while(!stk.empty()){
			if(!vis[stk.back()]) dfs(stk.back()), ans++;
			stk.pop_back();
		}	
		cout << "Case " << cs++ << ": "  << ans << endl;
	}
}