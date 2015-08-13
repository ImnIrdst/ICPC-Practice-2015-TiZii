#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX 5000
#define vi vector<int> 

using namespace std;

struct edge{ int u,v,clear; };

vector<edge> ve; vector< vi > adj;  int vis[MAX+10],dad[MAX+10],n; vector<int> path;

void bfs(int s, int f){
	queue<int> q; q.push(s); vis[s]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		//cout << "bfs" << u << endl;
		if(u==f) return;
		for(int i=0 ; i<adj[u].size() ; i++){
			int v=adj[u][i];
			if(!vis[v]){
				vis[v]=vis[u]+1; dad[v]=u; q.push(v);
			}
		}
	}
}

void path_cons(int u){
	if(u==-1) return;
	path_cons(dad[u]); 
	path.push_back(u+1);
}

int main(){
	int u,v;
	while(cin >> n && n){
		adj.assign(n,vi()); ve.clear();
		for(int i=0; i<n-1 ; i++){
			cin >> u >> v; u--,v--;
			
			adj[u].push_back(v); adj[v].push_back(u);
		}
		int m; cin >> m;
		while(m--){
			cin >> u >> v; u--,v--;
			memset(vis, 0, sizeof vis); memset(dad, -1, sizeof dad); path.clear();
			bfs(u,v); path_cons(v); int len=path.size(); 
			//for(int i=0 ; i<len ; i++) cout << path[i] << " "; cout << endl;
			//for(int i=0 ; i<n ; i++) cout << dad[i] << " "; cout << endl;
			if(len%2==0) printf("The fleas jump forever between %d and %d.\n", min(path[len/2], path[len/2-1]), max(path[len/2], path[len/2-1]));
			if(len%2==1) printf("The fleas meet at %d.\n", path[len/2]);
		}
	}
	return 0;
}