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
#define MAX 5000
#define vi vector<int> 

using namespace std;

vector< vi > adj; vector<int> owner, visRight, visLeft; int r,c,n;

int altpath(int u){
	visLeft[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(visRight[v-r]) continue; visRight[v-r]=1;
		if(owner[v]==-1 || altpath(owner[v])){
			owner[v]=u; owner[u]=v; return 1;
		}
	}
	return 0;
}

int main(){
	int u,v;
	while(cin >> r >> c >> n && (r||c||n)){
		 adj.assign(r+1,vi());
		while(n--){cin >> u >> v; adj[u].push_back(v+r);}
		int MCBM=0; owner.assign(r+c+1,-1);
		for(int u=1 ; u<=r ; u++){
			visLeft.assign(r+1,0); visRight.assign(c+1,0);
			MCBM+=altpath(u);
		}
		visLeft.assign(r+1,0); visRight.assign(c+1,0);
		for(int u=1 ; u<=r ; u++){
			if(owner[u]==-1) altpath(u);
		}
		printf("%d", MCBM);
		for(int u=1 ; u<=r ; u++) if(visLeft[u]==0) printf(" r%d",u );
		for(int u=1 ; u<=c ; u++) if(visRight[u]==1) printf(" c%d",u );
		printf("\n");
	}
	return 0;
}