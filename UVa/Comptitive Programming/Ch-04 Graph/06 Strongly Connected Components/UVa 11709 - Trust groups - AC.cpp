#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <map>
#define MAX 1000

using namespace std;

int dfsNum[MAX+10],dfsLow[MAX+10],vis[MAX+10],n,m,lev,ans; vector<int> SCC,adj[MAX+10];
map<string, int> mp;

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
	string str,str2;
	while(cin >> n >> m && (n || m)){
		memset(dfsNum,0,sizeof dfsNum); for(int i=0 ; i<MAX+10 ; i++) adj[i].clear(); 
		memset(dfsLow,0,sizeof dfsLow); memset(vis,0,sizeof vis); 
		lev=1; ans=0; mp.clear();
		char c1,c2; cin.ignore();
		for(int i=0 ; i<n ; i++){
			getline(cin, str); mp[str]=i;
		}
		for(int i=0 ; i<m ; i++){
			getline(cin, str); getline(cin, str2);
			adj[mp[str]].push_back(mp[str2]);
		}
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0) dfs(i);
		}
		cout << ans << endl;
	}
	return 0;
}
