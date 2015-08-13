#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <map>
#define INF (int)1e9
#define MAX 5000
#define vi vector<int> 

using namespace std;

vector< vi > adj; vector<int> owner, vis; int n,m; map<string,int> mp;

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
	mp["XS"]=0; mp["S"]=1; mp["M"]=2; mp["L"]=3; mp["XL"]=4; mp["XXL"]=5; 

	int tmp,tc,t=1; cin >> tc; string str;
	while(tc--){
		cin >> n >> m; adj.assign(n+m,vi());
		for(int i=0 ; i<m ; i++){
			cin >> str;
			for(int j=mp[str] ; j<n ; j+=6){
				adj[j].push_back(i+n);
			}
			cin >> str;
			for(int j=mp[str] ; j<n ; j+=6){
				adj[j].push_back(i+n);
			}
		}
		int MCBM=0; owner.assign(n+m,-1);
		for(int u=0 ; u<n ; u++){
			vis.assign(n,0); MCBM+=altpath(u);
		}
		if(MCBM==m) cout << "YES" << endl;
		if(MCBM!=m) cout << "NO" << endl;
	}
	return 0;
}