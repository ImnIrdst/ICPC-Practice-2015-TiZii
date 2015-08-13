#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
//#define cin fin
#define INF (int)1e9
#define MAX (int)1e6+10
#define node pair<int,int>
#define cost first
#define idx second

using namespace std;

int n, m, dist[1010], IsOnNeg[1010]; 
vector<node> adj[1010]; vector<int> adj2[1010];

int dfs(int u){
	IsOnNeg[u]=1;
	for(int i=0 ; i<adj2[u].size() ; i++){
		int v = adj2[u][i];
		if(!IsOnNeg[v]) dfs(v);
	}
}

int main(){
	int tc,cs=1; cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i=0 ; i<n ; i++){
			adj[i].clear(); adj2[i].clear(); dist[i]=INF;
		}
		int u,v,w;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> w;
			adj[  v].push_back(node(w,u));
			adj2[ v].push_back(u);
		}
		dist[0]=0;
		for(int k=0 ; k<n ; k++){
			for(int u=0 ; u<n ; u++){
				for(int j=0 ; j<adj[u].size() ; j++){
					node v=adj[u][j];
					if(dist[v.idx]>dist[u]+v.cost){
						dist[v.idx]=dist[u]+v.cost;
					}
				}
			}
		}
		bool HasNegCyc=0; vector<int> OnNeg;
		for(int u=0 ; u<n ; u++){
			for(int j=0 ; j<adj[u].size() ; j++){
				node v=adj[u][j];
				if(dist[v.idx]>dist[u]+v.cost){
					HasNegCyc=1; OnNeg.push_back(u);
				}
			}
		}
		cout << "Case " << cs++ << ":";
		if(!HasNegCyc){
			cout << " impossible" << endl;
		}
		else{
			memset(IsOnNeg,0,sizeof IsOnNeg);
			for(int i=0 ; i<OnNeg.size() ; i++){
				if(!IsOnNeg[OnNeg[i]]) dfs(OnNeg[i]);
			}
			for(int i=0 ; i<n ; i++){
				if(IsOnNeg[i]) cout << " " << i;
			}
			cout << endl;
		}
	}
}