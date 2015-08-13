#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define MAX (20+20+10)
#define CLR(a,v) memset(a,v,sizeof a)
#define vi vector<int>
#define INF (int)1e9
using namespace std;

int dad[MAX], f[MAX]; int n,m,N,s,t; vector<double> dist;
int res[MAX][MAX]; double maxflow,mincost,cost[MAX][MAX];

int bellman(int s, int t){
	dist.assign(N,(double)INF); CLR(dad,-1); CLR(f,0);
	dist[s]=0; f[s]=INF;
	for(int i=0 ; i<N-1 ; i++){
		for(int u=0 ; u<N ; u++){
			for(int v=0 ; v<N ; v++){
				if(dist[v]>dist[u]+cost[u][v] && res[u][v]>0){
					dist[v]=dist[u]+cost[u][v];
					f[v]=min(f[u],res[u][v]);
					dad[v]=u;
				}
			}
		}
	}
	return f[t];
}

double augment(int s, int t, int f){
	double COST=0;
	for(int v=t, u=dad[t]; u!=-1 ; v=dad[v], u=dad[u]){
		res[u][v]-=f; res[v][u]+=f;
		COST+=f*cost[u][v];
	}
	return COST;
}

double MCMF(){
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			cost[j][i]=-1*cost[i][j];
		}
	}
	while(true){
		int f=bellman(s, t);
		if(f==0) break;
		mincost+=augment(s,t,f); maxflow+=f;
	}
	return mincost;
}

int main(){
	//int m,u,v,c,tmp;
	while(cin >> n >> m && (n||m)){
		CLR(cost,0); CLR(res,0); 
		double c; s=0,t=n+m+1; N=n+m+2;
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=m ; j++){
				cin >> c;
				cost[j][m+i]=c; res[j][m+i]=1;
				cost[s][j]=0; res[s][j]=1;
			}
			cost[m+i][t]=0; res[m+i][t]=1;
		}
		mincost=0; maxflow=0;
		printf("%.2lf\n", MCMF()/n+(double)1e-6);
	}
	return 0;
}