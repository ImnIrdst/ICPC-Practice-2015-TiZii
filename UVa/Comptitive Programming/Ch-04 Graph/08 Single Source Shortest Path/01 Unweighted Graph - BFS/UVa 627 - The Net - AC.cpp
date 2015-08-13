#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vvi;

vvi adj; vi vis, par;

void printPath(int i){
	if(par[i]==-1) cout << i+1;
	else printPath(par[i]), cout << " " << i+1;
}

int main(){
	int n,m;
	while(cin >> n){
		int u, v; char c;
		adj.assign(n,vi());
		for(int i=0 ; i<n ; i++){
			cin >> u; u--; cin.get();
			while(cin.peek()!='\n'){
				cin >> v; adj[u].push_back(v-1);
				if(cin.get()=='\n') break;
			}
		}
		int m; cin >> m; 
		cout << "-----" << endl;
		while(m--){
			int s, g; 
			cin >> s >> g; s--, g--;
			vis.assign(n,-1); 
			par.assign(n,-1);
			queue<int> q; q.push(s); vis[s]=0;
			while(!q.empty()){
				int u = q.front(); q.pop();
				if( u == g ) break;
				for(int i=0 ; i<adj[u].size() ; i++){
					int v = adj[u][i];
					if( vis[v]==-1 ){
						q.push(v), vis[v]=vis[u]+1; par[v]=u;
					}
				}
			}
			if(par[g]==-1) cout << "connection impossible" << endl;
			if(par[g]!=-1) printPath(g), cout << endl;
		}
	}
}