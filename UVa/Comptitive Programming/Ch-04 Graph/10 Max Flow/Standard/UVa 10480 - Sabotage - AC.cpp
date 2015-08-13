#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#define INF (int)1e9
#define MAX 50+10

using namespace std;

int res[MAX][MAX],cap[MAX][MAX],mf,f,s=0,t=1,n,m,par[MAX]; vector<int> dist,adj[MAX];

void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

void bfs(int s){
	memset(par,-1,sizeof par); dist.assign(n,INF);
	dist[s]=0; queue<int> q; q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==t) break;
		for(int i=0 ; i<adj[u].size(); i++){
			int v=adj[u][i];
			if(res[u][v]>0 && dist[v]==INF){
				dist[v]=dist[u]+1; q.push(v); par[v]=u;
			}
		}
	}
}

int main(){
	int t=1;
	while(cin >> n >> m && (n||m)){
		mf=0; memset(res,0,sizeof res); memset(cap,0,sizeof cap);
		for(int i=0 ; i<n ; i++) adj[i].clear();
		int u,v,c;
		while(m--){
			cin >> u >> v >> c; u--; v--;
			res[u][v]+=c; res[v][u]+=c;
			cap[u][v]+=c; cap[v][u]+=c;
			adj[u].push_back(v); adj[v].push_back(u);
		}
		while(1){
			f=0; bfs(s);
			agument(t,INF);
			if(f==0) break;
			mf+=f;
		}
		bfs(s);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(dist[i]!=INF && dist[j]==INF && res[i][j]<=0 && cap[i][j]){
					printf("%d %d\n",i+1,j+1);
				}
			}
		}
		printf("\n");
	}
	return 0;
}