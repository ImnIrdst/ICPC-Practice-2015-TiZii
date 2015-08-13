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
#define MAX 200+10

using namespace std;

int res[MAX][MAX],mf,f,s,t,n,m,par[MAX]; vector<int> dist,adj[MAX];
//0 barisal , 1 -> n+n regulators, 2*n+1 Dhaka
void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	int t=1,tmp;
	while(cin >> n && n){
		memset(res,0,sizeof res); for(int i=0 ; i<MAX ; i++) adj[i].clear();
		s=0; t=2*n+1; mf=0;
		for(int i=1 ; i<=n ; i++){
			cin >> tmp; res[i][i+n]=tmp;
			adj[i].push_back(n+i); adj[i].push_back(n+i);
		}
		int u,v,c,m; cin >> m;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> c;
			res[u+n][v]+=c;
			adj[u+n].push_back(v); adj[v].push_back(u+n);
		}
		int b,d; cin >> b >> d;
		for(int i=0 ; i<b ; i++){
			cin >> v;
			res[s][v]=INF;
			adj[s].push_back(v); adj[v].push_back(s);
		}
		for(int i=0 ; i<d ; i++){
			cin >> v;
			res[v+n][t]=INF;
			adj[v+n].push_back(t); adj[t].push_back(v+n);
		}
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(n*2+2,INF);
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
