#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <sstream>
#include <queue>
#define INF (int)1e9
#define MAX 100

using namespace std;

int  dist[MAX+10], vis[MAX+10],n; vector<int> adj[MAX+10],stk;

int dfs(int u){
	vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(!vis[v]) dfs(v);
	}
	stk.push_back(u);
}

int main(){
	int t=1;
	while(cin >> n && n){
		for(int i=0 ; i<MAX+10 ; i++) adj[i].clear();
		int u,v,s; cin >> s;
		while(cin >> u >> v && (u||v)){
			u--,v--; adj[u].push_back(v);
		}
		stk.clear(); memset(vis,0,sizeof vis); memset(dist,0,sizeof dist);
		dfs(s-1); int maxdist=-1, maxv=INF;
		while(!stk.empty()){
			int u=stk.back(); stk.pop_back();
			for(int i=0 ; i<adj[u].size() ; i++){
				int v=adj[u][i];
				if(dist[v]<=dist[u]+1){
					dist[v]=dist[u]+1;
					maxdist=max(maxdist,dist[v]);
				}
			}
		}
		for(int i=0 ; i<n ; i++){
			if(dist[i]==maxdist) maxv=min(maxv,i);
		}
		//for(int i=0 ; i<n ; i++) cout << dist[i] << " "; cout << endl; // debug
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",t++,s,maxdist,maxv+1);
	}
	return 0;
}