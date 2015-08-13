#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define INF (int) 1e6
#define MAX (1000+10)
#define pii pair<int,int>

using namespace std;

int n, m, dfsLow[MAX+10], dfsNum[MAX+10],parent[MAX+10] , lev, dfsRoot,rootChilds;
vector<int> adj[MAX+10]; set<pii> ans; set<int> artPoints;

void dfs(int u){
	 dfsLow[u]=dfsNum[u]=lev++;
	 for(int i=0 ; i<adj[u].size() ; i++){
		 int v=adj[u][i];
		 if(parent[u]!=v &&
		 	 		 ans.find(pii(u,v))==ans.end() &&
		 	 		 ans.find(pii(v,u))==ans.end())
		 	 			ans.insert(pii(u,v));
		 if(dfsNum[v]==0){
			 parent[v]=u; dfs(v);

			 if(dfsLow[v]>dfsNum[u])//u,v is bridge 
				ans.insert(pii(u,v)),
				ans.insert(pii(v,u));
			 
			 dfsLow[u]=min(dfsLow[u],dfsLow[v]);
		 }
		 else if(parent[u]!=v)
			 dfsLow[u]=min(dfsLow[u],dfsNum[v]);
	 }
}

int main(){
	int cs=1;
	while(cin >> n >> m && (n||m)){
		for(int i=0 ; i<MAX+10; i++) dfsLow[i]=parent[i]=dfsNum[i]=0, adj[i].clear();
		ans.clear(); artPoints.clear(); lev=1; int tmp,u,v;//initialization
		for(int i=0 ; i<m ; i++){
			cin >> u >> v; u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);		
		}
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0) dfs(i); 
		}
		printf("%d\n\n", cs++);
		set<pii>::iterator itr; // print answer
		for(itr=ans.begin() ; itr!=ans.end() ; itr++) 
			printf("%d %d\n", itr->first+1, itr->second+1);
		printf("#\n");
	}
	return 0;
}
