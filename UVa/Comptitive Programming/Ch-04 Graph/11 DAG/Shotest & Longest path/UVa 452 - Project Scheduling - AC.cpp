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
#define MAX 26

using namespace std;

int cost[MAX+10], dist[MAX+10], vis[MAX+10],n,ans; vector<int> adj[MAX+10],stk;

int dfs(int u){
	vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(!vis[v]) dfs(v);
	}
	stk.push_back(u);
}

int main(){
	int tc; cin >> tc; cin.ignore(); cin.ignore(); 
	char c,c2; int w; string str; stringstream sstr;
	while(tc--){
		ans=-1,n=0; for(int i=0 ; i<MAX+10 ; i++) adj[i].clear();//memset(dist,0,sizeof dist); memset(cost,0,sizeof cost);
		while(getline(cin,str) && str.length()){
			//printf("getline: %s\n", str.c_str()); // debug
			sstr.clear(); sstr << str; n++;
			sstr >> c >> w; dist[c-'A']=cost[c-'A']=w; ans=max(ans,w);
			while(sstr >> c2){
				adj[c2-'A'].push_back(c-'A');
			}
		}
		stk.clear(); memset(vis,0,sizeof vis);
		for(int u=0 ; u<MAX+10 ; u++){
			if(!vis[u]) dfs(u);
		}
		while(!stk.empty()){
			int u=stk.back(); stk.pop_back();
			for(int i=0 ; i<adj[u].size() ; i++){
				int v=adj[u][i];
				if(dist[v]<dist[u]+cost[v]){
					dist[v]=dist[u]+cost[v];
					ans=max(ans,dist[v]);
				}
			}
		}
		//for(int i=0 ; i<n ; i++) printf("%c:%d\n",(char)i+'A',dist[i] ); cout << endl; // debug
		cout << ans << endl;
		if(tc) cout << endl;
	}
	return 0;
}