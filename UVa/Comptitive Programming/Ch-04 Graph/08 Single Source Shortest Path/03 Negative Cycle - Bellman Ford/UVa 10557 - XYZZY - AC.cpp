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
#define MAX 100

using namespace std;

vector<int> adj[MAX+10]; int n, energy[MAX+10], dist[MAX+10], vis[MAX+10];

bool dfs(int u){
	vis[u]=1; if(u==n) return true;
	bool connected=false;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(!vis[v]) connected|=dfs(v);
	}
	return connected;
}

int main(){
	int m,tmp;
	while(cin >> n && n!=-1){
		bool winnable=false;
		for(int i=1 ; i<=n ; i++){
			adj[i].clear(); dist[i]=-1*INF;
			cin >> energy[i] >> m;
			for(int j=0 ; j<m ; j++){
				cin >> tmp; adj[i].push_back(tmp);
			}
		}
		dist[1]=100;
		for(int k=0 ; k<n-1 ; k++){
			for(int u=1 ; u<=n ; u++){
				for(int i=0 ; i<adj[u].size(); i++){
					int v=adj[u][i];
					if(dist[v]<dist[u]+energy[v] && dist[u]+energy[v]>0){
						dist[v]=dist[u]+energy[v];
					}
				} 
			}
		}
		if(dist[n]>=0) winnable=true;
		for(int u=1 ; u<=n && !winnable ; u++){
			for(int i=0 ; i<adj[u].size() && !winnable ; i++){
				int v=adj[u][i];
				if(dist[v]<dist[u]+energy[v] && dist[u]+energy[v]>0){
					memset(vis,0,sizeof vis);
					if(dfs(u)) 
						winnable=true;
				}
			} 
		}
		cout << (winnable ? "winnable" : "hopeless" ) << endl;
	}

	return 0;
}