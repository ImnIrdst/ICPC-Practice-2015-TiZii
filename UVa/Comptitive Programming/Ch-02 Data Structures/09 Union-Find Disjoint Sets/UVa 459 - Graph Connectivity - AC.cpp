#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

vector<int> adj[30]; bool vis[30];

void bfs(int u){
	int v; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		v=adj[u][i];
		if(!vis[v]){
			bfs(v);
		}
	}
}

int main(){
	int tc; cin >> tc; int first=true;
	while(tc--){
		for(int i=0 ; i<30 ; i++){adj[i].clear(); vis[i]=0;}
		char c; cin >> c; cin.ignore(); int n=c-'A'; n++;
		string e;
		while(getline(cin,e) && e.length()!=0){
			adj[e[0]-'A'].push_back(e[1]-'A');
			adj[e[1]-'A'].push_back(e[0]-'A');
		}
		int ans=0;
		for(int i=0 ; i<n ; i++){
			if(!vis[i]){
				bfs(i); ans++;
			}
		}
		if(!first) cout << endl; first=false;
		cout << ans << endl;
	}
	return 0;
}