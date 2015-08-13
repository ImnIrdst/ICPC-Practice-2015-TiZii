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
#define vi vector<int>

using namespace std;

vector<vi> adj; vi owner,vis;
int n,m,a[100+100+10];

int altpath(int u){
	if(vis[u]) return 0; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(owner[v]==-1 || altpath(owner[v])){
			owner[v]=u; return 1;
		}
	}
	return 0;
}

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		int n,m; 
		cin >> n; for(int i=0 ; i<n ; i++) cin >> a[i];
		cin >> m; for(int i=0 ; i<m ; i++) cin >> a[n+i];
		adj.assign(n+m,vi());
		for(int i=0 ; i<n ; i++){
			for(int j=n ; j<n+m ; j++){
				if((a[i]!=0 && a[j]%a[i]==0) || a[j]==0){
					adj[i].push_back(j);
				}
			}
		}
		int MCBM=0; owner.assign(n+m,-1);
		for(int i=0 ; i<n ; i++){
				vis.assign(n,0); MCBM+=altpath(i);
		}
		printf("Case %d: %d\n",t++,MCBM );
	}
	return 0;
}