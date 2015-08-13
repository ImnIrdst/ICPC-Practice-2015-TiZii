#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vii;

const int  MAX = 1000+10;

vii adj; vi vis; int ok, n; 

void dfs(int u){
	vis[u]=1;
	for(int i=1 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(!vis[v]) dfs(v);
		else ok = 0;
	}
}

int main(){
	int u, v, cs=1;
	while(cin >> u >> v && (u>=0 || v>=0)){
		map<int, int> mp; n=0;
		adj.assign(MAX, vi(1,0)); vis.assign(MAX,1);
		while(u>0||v>0){
			if(!mp.count(u)) mp[u]=n++; 
			if(!mp.count(v)) mp[v]=n++; 
			adj[mp[u]].push_back(mp[v]); vis[mp[u]]=vis[mp[v]]=0; adj[mp[v]][0]++;
			cin >> u >> v ;
		}
		int root=0;
		for(int i=0 ; i<n ; i++){
			if(adj[i][0]==0 && vis[i]==0){
				root = i; break;
			}
		}

		ok=1; dfs(root);
		for(int i=0 ; i<MAX ; i++){
			ok&=(vis[i]==1);
		}	
		cout << "Case " << cs++ << " ";
		if(ok==true ) cout << "is a tree." << endl;
		if(ok==false) cout << "is not a tree." << endl;	
	}
}