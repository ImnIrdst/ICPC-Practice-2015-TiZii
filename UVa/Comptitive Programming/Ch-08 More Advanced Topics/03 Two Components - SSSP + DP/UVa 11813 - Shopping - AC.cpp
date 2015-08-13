#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
#include <functional>
#include <cstring>
#define vi   vector<int>
#define node pair<int,int>
#define vn   vector<node>
#define vvn  vector< vn >
#define cost first
#define idx  second
#define eps  1e-9
#define inf  1e9
#define MAX  (10+3)

using namespace std;


vvn adj; vi Cost; int mp[MAX];

int adj2[MAX][MAX], dp[MAX][1<<MAX], n, m, n2;

int TSP(int pos, int bit){
	int& dpp = dp[pos][bit];
	if(bit == (1<<n2)-1) return adj2[pos][0];
	if(dpp != (-1)    ) return dpp; dpp=inf;
	for(int i=0 ; i<n2 ; i++){
		if( !(bit&(1<<i)) ){
			dpp=min(dpp,TSP(i,bit|(1<<i))+adj2[pos][i]);
		}
	}
	return dpp;
}

int dijkstra(int s, int t){
	priority_queue< node ,vector< node >, ::greater< node > > pq;
	pq.push(node(0,s)); Cost = vector<int>(n,inf);
	while(!pq.empty()){
		node u = pq.top(); pq.pop();
		if(u.idx == t) return u.cost;
		if(u.cost > Cost[u.idx]) continue;
		for(int i=0 ; i<adj[u.idx].size() ; i++){
			node v = adj[u.idx][i];
			if(u.cost+v.cost<Cost[v.idx]){
				Cost[v.idx]=u.cost+v.cost;
				pq.push(node(Cost[v.idx],v.idx));
			}
		}
	}
	return inf;
}

int main(){
	int u, v, d, tc; cin >> tc;
	while(tc--){cin >> n >> m;
		adj.assign(n, vn());
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >>  d;
			adj[u].push_back(node(d,v));
			adj[v].push_back(node(d,u));
		}
		cin >> n2; n2++; mp[0]=0;
		for(int i=1 ; i<n2 ; i++){
			cin >> u; mp[i]=u;
		}
		for(int i=0 ; i<n2 ; i++){
			for(int j=i ; j<n2 ; j++){
				int dist=dijkstra(mp[i],mp[j]);
				adj2[i][j]=dist; adj2[j][i]=dist;
			}
		}
		memset(dp,-1,sizeof dp);
		cout << TSP(0,1) << endl;
	}
}
