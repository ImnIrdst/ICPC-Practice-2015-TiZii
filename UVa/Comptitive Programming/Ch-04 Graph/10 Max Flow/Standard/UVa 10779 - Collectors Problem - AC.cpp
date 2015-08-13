#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vii;

const int MAX = 100+10;
const int INF = 1e9;

int res[MAX][MAX],mf,f,s,t,n,m,par[MAX]; vii adj; vi vis;

void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	int tc, cs=1; cin >> tc;
	while(tc--){ cin >> n >> m;
		memset(res, 0, sizeof res); 
		mf = 0; adj.assign(n+m+2,vi());
		s  = 1; t = n+m+1;
		//Connect each person to stickers he has
		for(int i=1 ; i<=n ; i++){
			int k; cin >> k;
			while(k--){
				int stc; cin >> stc;
				if(!res[i][n+stc]) 
					adj[i].push_back(n+stc),
					adj[n+stc].push_back(i);
				res[i][n+stc]++;
			}
		}
		for(int i=2 ; i<=n ; i++){
			for(int j=n+1 ; j<=n+m ; j++){
				if(res[i][j]) res[i][j]--; // keep only extra ones
				else		  res[j][i]=1, // if how doesnt have a sticker connect sticker to him
							  adj[i].push_back(j),
				              adj[j].push_back(i);
			}
		}
		for(int j=n+1 ; j<=n+m ; j++){ // connect stickers to sink
			res[j][t] = 1;
			adj[j].push_back(t);
		}
		vi dist;
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(n+m+2,INF);
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
		printf("Case #%d: %d\n", cs++, mf);
	}
	return 0;}
