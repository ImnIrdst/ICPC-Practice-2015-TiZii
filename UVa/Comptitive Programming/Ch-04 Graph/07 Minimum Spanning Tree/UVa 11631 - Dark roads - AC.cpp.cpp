#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX_CITY 1000
#define MAX_FUEL 100
#define pii pair<int,int>
#define piii pair<int, pii >
#define COST first
#define U second.first
#define GAS second.second

#define W first
#define V second

using namespace std;

int n, m, dist[MAX_CITY+10][MAX_FUEL+10], p[MAX_CITY+10]; vector<pii> adj[MAX_CITY+10];

int dijkstra(int s, int c, int g){// s==source, c==capacity, g==goal
	for(int i=0 ; i<n ; i++) for(int j=0 ; j<=c ; j++) dist[[i][j]=INF;
	priority_queue< piii ,vector< piii > , ::greater< piii > > pq;
	pq.push(piii(0, s, 0)); dist[s][0]=INF;
	while(!pq.empty()){
		piii u=pq.top(); pq.pop();
		if(u.U==g) return u.COST;
		if(u.COST>dist[u.U][u.GAS]) continue;
		if(u.GAS+1 <= c && u.COST+p[u.U]<dist[u.U][u.GAS+1]){
			dist[u.U][u.GAS+1]=u.COST+p[u.U]; 
			pq.push(piii(u.COST+p[u.U],u.U,u.GAS+1));
		}
		for(int i=0 ; i<adj[u.U].size() ; i++){
			pii v=adj[u.U][i];
			if(v.W<=u.GAS && u.COST<dist[v.V][u.GAS-v.W]){
				dist[v.V][u.GAS-v.W]=u.COST;
				pq.push(piii(u.COST,v.V,u.u.GAS-v.W));
			}
		} 
	}
	return dist[g][c];
}

int main(){
	int x,y,w,c,s,g;
	while(cin >> n >> m){
		for(int i=0 ; i<n ; i++) cin >> p[i], adj[i].clear();
		for(int i=0 ; i<m ; i++){
			cin >> x >> y >> w;
			adj[x].push_back(pii(w,y));
			adj[y].push_back(pii(w,x));
		}
		int q; cin >> q;
		for(int i=0 ; i<q ; i++){
			cin >> c >> s >> g;
			int ans=dijkstra(s,c,g);
			if(ans==INF) cout << "impossible" << endl;
			else cout << ans << endl;
		}
	}
}