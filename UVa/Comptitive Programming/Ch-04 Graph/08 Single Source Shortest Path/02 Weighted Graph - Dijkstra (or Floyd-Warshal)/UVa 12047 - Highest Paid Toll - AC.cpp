#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#define ww first
#define vv second

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii > vvpii;

void Dijkstra(int s, const vvpii& adj, vi& dist,int n){
	priority_queue<pii, vpii, ::greater<pii> > pq;
	pq.push(pii(0,s)); dist.assign(n,1e9); dist[s]=0;
	while( !pq.empty() ){
		pii u = pq.top(); pq.pop();
		if( u.ww > dist[u.vv]) continue;
		for(int i=0 ; i<adj[u.vv].size() ; i++){
			pii v(u.ww +  adj[u.vv][i].ww, adj[u.vv][i].vv);
			if(v.ww >= dist[v.vv]) continue;
			dist[v.vv] = v.ww; pq.push(v);
		}
	}
}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while( tc-- ){
		int n, m, s, t, p; 
		cin >> n >> m >> s >> t >> p; s--, t--;
		vvpii adj1(n, vpii()), adj2(n, vpii());

		for(int i=0 ; i<m ; i++){
			int u, v, w; 
			cin >> u >> v >> w; u--, v--;
			adj1[u].push_back(pii(w,v));
			adj2[v].push_back(pii(w,u));
		}
		vi dist1, dist2;
		Dijkstra(s, adj1, dist1, n);
		Dijkstra(t, adj2, dist2, n);

		int ans = -1;
		for(int u=0 ; u<n ; u++){
			for(int j=0 ; j<adj1[u].size() ; j++){
				pii v = adj1[u][j];
				if( dist1[u] + dist2[v.vv] + v.ww <= p) ans = max(ans, v.ww);
			}
		}
		cout << ans << endl;
		
	}
}