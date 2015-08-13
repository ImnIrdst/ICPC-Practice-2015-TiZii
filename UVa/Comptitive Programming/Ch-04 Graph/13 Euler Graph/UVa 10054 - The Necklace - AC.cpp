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
#define MAX (50+10)
#define pii pair<int,int> 

using namespace std;

int adj[MAX][MAX],in[MAX],n=MAX,m; vector< pii > ans;

void euler(int u){
	for(int v=0 ; v<n ; v++){
		if(adj[u][v]>0){
			adj[u][v]--; adj[v][u]--;
			euler(v);
			ans.push_back(pii(u,v));
		}
	}
}

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		memset(adj,0,sizeof adj); memset(in,0,sizeof in); ans.clear();
		int u,v; cin >> m; 
		for(int i=0 ; i<m ; i++){
			cin >> u >> v;
			adj[u][v]++; adj[v][u]++;
			in[u]++; in[v]++;
		}
		int hasAns=true;
		for(int i=0 ; i<n ; i++){
			if(in[i]%2==1) hasAns=false;
		}
		if(hasAns){
			euler(v);
			if(ans.size()!=m) hasAns=false;
		}
		printf("Case #%d\n",t++);
		if(!hasAns) printf("some beads may be lost\n");
		else{
			while(!ans.empty()){
				printf("%d %d\n", ans.back().first, ans.back().second);
				ans.pop_back();
			}
		}
		if(tc) printf("\n");

	}
	return 0;
}