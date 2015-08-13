#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

int main(){
	int n; cin >> n;
	vvi adj(n, vi());
	for(int u=0 ; u<n ; u++){
		int m; cin >> m;
		for(int i=0 ; i<m ; i++){
			int v; cin >> v; adj[u].push_back(v);
		}
	}

	int tc;
	cin >> tc;
	while( tc-- ){
		int s; cin >> s; 
		
		if(adj[s].empty()){
			cout << 0 << endl; continue;
		}

		vi vis(n, -1), boom(n,0);
		queue<int> q; q.push(s); vis[s]=0;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i=0 ; i<adj[u].size() ; i++){
				int v = adj[u][i];
				if(vis[v]==-1) 
					vis[v]=vis[u]+1, boom[vis[v]]++, q.push(v);
			}
		}

		int Max=-1, Day=0;
		for(int i=1 ; i<n ; i++){
			if(boom[i]>Max) Max=boom[i], Day=i;
		}

		cout << Max << " " << Day << endl;
	}
}