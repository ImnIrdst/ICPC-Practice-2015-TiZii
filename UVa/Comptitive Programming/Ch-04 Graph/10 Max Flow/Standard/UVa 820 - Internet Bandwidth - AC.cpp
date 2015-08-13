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
	int tc=1;
	while(cin >> n && n){
		mf=0; memset(res,0,sizeof res); for(int i=0 ; i<n ; i++) adj[i].clear();
		cin >> s >> t >> m; s--; t--;
		int u,v,c;
		while(m--){
			cin >> u >> v >> c; u--; v--;
			res[u][v]+=c; res[v][u]+=c;
			adj[u].push_back(v); adj[v].push_back(u);
		}
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(n,INF);
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
		printf("Network %d\n", tc++);
		printf("The bandwidth is %d.\n\n", mf);
	}
	return 0;
}