#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
#include <cstring>
#define ww first
#define uu second

using namespace std;

typedef pair<int,int> pii;
typedef vector< pii > vpii;
typedef vector< vpii> vvpii;
typedef vector< int > vi;

const int MAX = 100 + 10;
const int INF = 1e9;

vvpii adj; vi dist, par; bool used[MAX][MAX]; int n;

void dijkstra(int s, int g){
	dist.assign(n,INF); 
	priority_queue<pii, vpii, ::greater<pii> > pq;
	pq.push(pii(0,s)); dist[s]=0;
	while(pq.size()){
		int u = pq.top().uu, w = pq.top().ww; pq.pop();
		if( u == g ) return ;
		if( w > dist[u] ) continue;

		for(int i=0 ; i<adj[u].size() ; i++){
			int v = adj[u][i].uu;
			if( used[u][v] ) continue;
			if( w + adj[u][i].ww < dist[v] ){
				dist[v] = w + adj[u][i].ww; par[v] = u;
				pq.push(pii(dist[v], v));
			}
		}
	}
}

int main(){
	while(cin >> n && n){
		adj.assign(n,vpii()); par.assign(n,-1);
		memset(used , 0,sizeof used);
		int m,u,v,w; cin >> m;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> w; u--,v--;
			adj[u].push_back(pii(w,v));
			adj[v].push_back(pii(w,u));
		}
		dijkstra(0, n-1);
		if(dist[n-1] == INF){
			cout << "Back to jail" << endl; continue;
		}
		
		int ans = dist[n-1];
		for(int v = n-1 ; v!=0 ; v=par[v]){
			int u = par[v]; used[u][v]=true;
			for(int i=0 ; i<adj[u].size() ; i++){
				int v2 = adj[u][i].uu;
				if( v2 == par[u] ) adj[u][i].ww *= -1;
			}
		}
		dijkstra(0,n-1);
		if(dist[n-1] == INF){
			cout << "Back to jail" << endl; continue;
		}
		ans += dist[n-1]; cout << ans << endl;
	}
}