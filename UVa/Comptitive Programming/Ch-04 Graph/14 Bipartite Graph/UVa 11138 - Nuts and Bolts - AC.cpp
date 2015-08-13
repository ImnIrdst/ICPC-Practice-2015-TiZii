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

vector< vi > adj; vector<int> owner, vis; int n,b;

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
	int tmp,tc,t=1; cin >> tc;
	while(tc--){
		cin >> n >> b; adj.assign(n+b,vi());
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<b ; j++){
				cin >> tmp; if(tmp==1) adj[i].push_back(j+n);
			}
		}
		int ans=0; owner.assign(n+b,-1);
		for(int u=0 ; u<n ; u++){
			vis.assign(n,0); ans+=altpath(u);
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", t++, ans);
	}
	return 0;
}