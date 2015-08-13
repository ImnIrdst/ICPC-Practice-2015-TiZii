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
#define MAX 1000

using namespace std;

int vis[MAX+10], path_cnt[MAX+10],n,m,tmp,ans; vector<int> adj[MAX+10],stk;

int dfs(int u){
	vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(!vis[v]) dfs(v);
	}
	stk.push_back(u);
}

int main(){
	bool first=true;
	while(cin >> n){
		for(int i=0 ; i<MAX+10 ; i++) adj[i].clear();//memset(dist,0,sizeof dist); memset(cost,0,sizeof cost);
		for(int i=0 ; i<n ; i++){
			cin >> m; 
			while(m--){
				cin >> tmp; adj[i].push_back(tmp);
			}
		}	
		stk.clear(); memset(vis,0,sizeof vis); 
		for(int u=0 ; u<MAX+10 ; u++){
			if(!vis[u]) dfs(u);
		}
		memset(path_cnt,0,sizeof path_cnt); path_cnt[0]=1; ans=0;
		while(!stk.empty()){
			int u=stk.back(); stk.pop_back();
			if(adj[u].size()==0) ans+=path_cnt[u];
			for(int i=0 ; i<adj[u].size() ; i++){
				int v=adj[u][i];
				path_cnt[v]+=path_cnt[u];
			}
		}
		if(!first) cout << endl; first=false;
		cout << ans << endl;
	}
	return 0;
}