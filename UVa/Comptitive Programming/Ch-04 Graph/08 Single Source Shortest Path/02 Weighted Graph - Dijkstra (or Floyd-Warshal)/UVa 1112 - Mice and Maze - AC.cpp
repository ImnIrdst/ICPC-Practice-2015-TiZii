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
	cin >> tc;
	while( tc-- ){
		int n, m, f, t;
		cin >> n >> f >> t >> m;
		vvpii adj(n, vpii());

		
		for(int i=0 ; i<m ; i++){
			int u, v, w;
			cin >> u >> v >> w; u--, v--;
			adj[v].push_back(pii(w,u));
		}

		priority_queue<pii, vpii, ::greater<pii> > pq;
		pq.push(pii(0,f-1)); vi dist(n,1e9); dist[f-1]=0;
		while( !pq.empty() ){
			pii u = pq.top(); pq.pop();
			if( u.ww > t || u.ww > dist[u.vv]) continue;
			for(int i=0 ; i<adj[u.vv].size() ; i++){
				pii v(u.ww +  adj[u.vv][i].ww, adj[u.vv][i].vv);
				if(v.ww >= dist[v.vv]) continue;
				dist[v.vv] = v.ww; pq.push(v);
			}
		}

		int cnt=0;
		for(int i=0 ; i<n ; i++){
			if(dist[i]<=t) cnt++;
		}

		cout << cnt << endl; if(tc) cout << endl;
	}
}