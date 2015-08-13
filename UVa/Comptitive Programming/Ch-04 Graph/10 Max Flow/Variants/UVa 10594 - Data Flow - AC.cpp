#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#define MAX (100+10)
#define INF LLONG_MAX

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

vvll cap, flow , cost; vi found; vll dist, pi, f; vpii dad; 
ll mincost, maxflow; int N,s,t;

void relax(int s, int k, ll cap, ll cost, int dir){
	ll val=dist[s]+pi[s]-pi[k]+cost;
	if(dist[k]>val && cap){
		dist[k]=val; dad[k]=pii(s,dir); f[k]=min(cap,f[s]);
	}
}

ll dijkstra(int s, int t){
	found.assign(N,0); dist.assign(N,INF); f.assign(N,0); dad.assign(N,pii(-1,2));
	dist[s]=0; f[s]=INF;
	while(s!=-1){
		int best=-1; found[s]=true;
		for(int k=0 ; k<N; k++){
			if(found[k]) continue;
			relax(s,k,cap[s][k]-flow[s][k],cost[s][k],1);
			relax(s,k,flow[k][s],-1*cost[k][s],-1);
			if(best==-1 || dist[k]<dist[best]) best=k;
		}
		s=best;
	}
	for(int k=0 ; k<N ; k++){
		pi[k]=min(pi[k]+dist[k],INF);
	}
	return f[t];
}

void MCMF(){
	ll cur;
	while(cur=dijkstra(s,t)){
		maxflow+=cur;
		for(int x=t, dx=dad[t].first ; x!=s ; x=dad[x].first, dx=dad[dx].first){
			if(dad[x].second==1){
				flow[dx][x]+=cur; mincost+=cur*cost[dx][x];
			}
			if(dad[x].second==-1){
				flow[x][dx]-=cur; mincost-=cur*cost[x][dx];
			}
		}
	}
}

int main(){
	ll n,m,u,v,c;
	while(cin >> n >> m && (n||m)){
		
		s=1,t=n+1; N=n+2; pi.assign(N,INF);
		cap.assign(N,vll(N,0)); flow.assign(N,vll(N,0)); cost.assign(N,vll(N,0));

		vector<ll> U,V,C; 
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> c;
			U.push_back(u); V.push_back(v); C.push_back(c);

		}
		ll D, K; cin >> D >> K;
		for(int i=0 ; i<m ; i++){
			u=U[i] , v=V[i], c= C[i];
			cost[u][v]=c; cost[v][u]=c;
			 cap[u][v]=K;  cap[v][u]=K;
		}
		cap[n][t]=D; cost[n+1][t]=0;
		mincost=0; maxflow=0; MCMF();
		if(maxflow==D) cout << mincost << endl;
		else cout << "Impossible." << endl;
	}
	return 0;
}