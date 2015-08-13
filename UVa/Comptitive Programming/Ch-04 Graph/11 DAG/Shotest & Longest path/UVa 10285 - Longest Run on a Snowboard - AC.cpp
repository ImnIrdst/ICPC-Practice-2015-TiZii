#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <sstream>
#include <queue>
#define INF (int)1e9
#define MAX (100+10)
#define v(x,y) (x)*m+(y)
#define b(u) a[u/m][u%m]

using namespace std;

int a[MAX][MAX], dist[MAX*MAX], vis[MAX*MAX],n,m; vector<int> adj[MAX*MAX],stk;
int dx[]={ 0, 0,+1,-1};
int dy[]={-1,+1, 0, 0};

void dfs(int u){
	vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(!vis[v]) dfs(v);
	}
	stk.push_back(u);
}

int check(int x, int y, int val){
	if(x<n && y<m && x>=0 && y>=0 && a[x][y]<val) return 1;
	return 0;
}

int main(){
	int tc; cin >> tc;  string str;
	while(tc--){
		cin >> str >> n >> m; for(int i=0 ; i<MAX*MAX ; i++) adj[i].clear(),vis[i]=0,dist[i]=1;
		for(int i=0 ; i<n ;i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
			}
		}
		for(int x=0 ; x<n ;x++){
			for(int y=0 ; y<m ; y++){
				for(int i=0 ; i<4 ; i++){
					if(check(x+dx[i],y+dy[i], a[x][y])){
						//printf("%d:%d\n",b(u),b(v) );
						adj[v(x,y)].push_back(v(x+dx[i],y+dy[i]));
					}
				}
			}
		}
		for(int i=0 ; i<MAX*MAX ; i++){
			if(!vis[i]) dfs(i);
		}
		int ans=1;
		while(!stk.empty()){
			int u=stk.back(); stk.pop_back();

			for(int i=0 ; i<adj[u].size() ; i++){
				int v=adj[u][i];
				if(dist[v]<dist[u]+1){ 
					dist[v]=dist[u]+1;  ans=max(ans,dist[v]);
				}
			}
		}
		str+= ": "; cout << str << ans << endl;
	}
	return 0;
}