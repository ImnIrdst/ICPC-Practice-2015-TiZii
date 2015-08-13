#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <map>
#define INF (int)1e9
#define MAX 100000

using namespace std;

int dfsNum[MAX+10],dfsLow[MAX+10],vis[MAX+10],n,m,lev,ans; vector<int> SCC,adj[MAX+10];

void dfs(int u){
	dfsLow[u]=dfsNum[u]=lev++; vis[u]=1; SCC.push_back(u);
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(dfsNum[v]==0) dfs(v);
		if(vis[v]) dfsLow[u]=min(dfsLow[u], dfsLow[v]);
	}
	if(dfsLow[u]==dfsNum[u]){
		for(int i=0, v ; !SCC.empty() ; i++){
			v=SCC.back(); SCC.pop_back(); vis[v]=0;
			if(v==u) break;
		}
		ans++; 
	}
}

int main(){
	int x,y,p;
	while(scanf("%d %d", &n, &m) && (n||m)){
		
		memset(dfsNum,0,sizeof dfsNum); memset(adj,0,sizeof adj); 
		memset(dfsLow,0,sizeof dfsLow); memset(vis,0,sizeof vis);
		lev=1; ans=0;
		
		for(int i=0, j=0 ; i<m ; i++){
			scanf("%d %d %d", &x, &y, &p); x--; y--;
			adj[x].push_back(y); if(p==2) adj[y].push_back(x);
		}
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0) dfs(i);
		}
		cout << (ans==1) << endl;
	}
	return 0;
}