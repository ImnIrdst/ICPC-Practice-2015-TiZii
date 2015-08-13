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
#define MAX (200+10)
#define pii pair<int,int> 

using namespace std;

int deg[MAX], vis[MAX], adj[MAX][MAX],n,m;

bool euler(int u){
	if(vis[u]) return 1;
	vis[u]=1; bool isEven=true;
	//cout << "bfs: " << u << endl;
	for(int v=0 ; v<n ; v++){
		if(adj[u][v]){
			isEven&=euler(v);
		}
	}
	return isEven&(deg[u]%2==0);
}

int main(){
	while(cin >> n >> m){
		int u,v; memset(vis,0,sizeof vis); 
		memset(deg,0,sizeof deg); memset(adj,0,sizeof adj);
		for(int i=0 ; i<m ; i++){
			cin >> u >> v; 
			adj[u][v]=adj[v][u]=1;
			deg[u]++; deg[v]++;
		}
		bool possible=euler(v) && m; //cout << possible << endl;
		for(int i=0 ; i<n && possible ; i++){
			if(!vis[i] && deg[i]>0) possible=false;
		}
		if(possible==1) cout << "Possible" << endl;
		if(possible==0) cout << "Not Possible" << endl;
	}
	return 0;
}