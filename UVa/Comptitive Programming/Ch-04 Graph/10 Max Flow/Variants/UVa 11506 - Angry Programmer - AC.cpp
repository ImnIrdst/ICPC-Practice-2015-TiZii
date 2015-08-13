#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#define INF ((int)1e9)
#define MAX 100+10

using namespace std;

int res[MAX][MAX],mf,f,s,t,n,m,par[MAX]; vector<int> dist,adj[MAX];

void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	int t=1;
	while(cin >> n >> m && (n||m)){

		memset(res,0,sizeof res); for(int i=0 ; i<2*n ; i++) adj[i].clear();
		s=0; t=n-1; mf=0; 
		res[s][s+n]=INF; res[t][t+n]=INF;
		adj[s].push_back(s+n); adj[t].push_back(t+n);
		adj[s+n].push_back(s); adj[t+n].push_back(t);
		int u,v,c;
		for(int i=0 ; i<n-2 ; i++){
			cin >> u >> c; u--;
			res[u][u+n]=c;
			adj[u+n].push_back(u); adj[u].push_back(u+n);
		}
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> c; u--; v--;
			res[u+n][v]+=c; res[v+n][u]+=c;
			adj[u+n].push_back(v); adj[v+n].push_back(u);
			adj[v].push_back(u+n); adj[u].push_back(v+n);
		}
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(n*2,INF);
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
			agument(t,INF);
			if(f==0) break;
			mf+=f;
		}
		cout << mf << endl;
	}
	return 0;
}