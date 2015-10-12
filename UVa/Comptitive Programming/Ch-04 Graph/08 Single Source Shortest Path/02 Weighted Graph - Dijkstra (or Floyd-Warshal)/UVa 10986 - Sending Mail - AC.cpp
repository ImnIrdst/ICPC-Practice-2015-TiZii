#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define ww first
#define vv second

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii > vvpii;

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while( tc-- ){
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		vvpii adj(n, vpii());

		
		for(int i=0 ; i<m ; i++){
			int u, v, w;
			cin >> u >> v >> w; 
			adj[u].push_back(pii(w,v));
			adj[v].push_back(pii(w,u));
		}

		priority_queue<pii, vpii, ::greater<pii> > pq;
		pq.push(pii(0,s)); vi dist(n,1e9); dist[s]=0;
		while( !pq.empty() ){
			pii u = pq.top(); pq.pop();
			if( u.ww > dist[u.vv]) continue;
			for(int i=0 ; i<adj[u.vv].size() ; i++){
				pii v(u.ww +  adj[u.vv][i].ww, adj[u.vv][i].vv);
				if(v.ww >= dist[v.vv]) continue;
				dist[v.vv] = v.ww; pq.push(v);
			}
		}
		cout << "Case #" << cs++ << ": ";
		if(dist[t]!=1e9) cout << dist[t] << endl;
		if(dist[t]==1e9) cout << "unreachable" << endl;
		
	}
}