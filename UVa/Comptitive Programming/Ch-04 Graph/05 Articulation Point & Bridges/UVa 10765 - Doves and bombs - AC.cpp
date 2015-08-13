#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

#define INF (int) 1e6
#define MAX (10000+100)
#define pii pair<int,int> 

using namespace std;

int n, m, dfsLow[MAX+10], dfsNum[MAX+10],parent[MAX+10] , lev, dfsRoot,rootChilds;
vector<int> adj[MAX+10], artPoints;

int cmp(const pii& a, const pii& b){
	return (a.first == b.first ? a.second<b.second : a.first>b.first);
}

void dfs(int u){
	 dfsLow[u]=dfsNum[u]=lev++;
	 for(int i=0 ; i<adj[u].size() ; i++){
		 int v=adj[u][i];
		 if(dfsNum[v]==0){
			 if(u==dfsRoot) rootChilds++;
			 parent[v]=u; dfs(v);
			 
			 if(dfsLow[v]>=dfsNum[u] && u!=dfsRoot)//u is articulation point
			 	artPoints[u]++;
			 dfsLow[u]=min(dfsLow[u],dfsLow[v]);
		 }
		 else if(parent[u]!=v)
			 dfsLow[u]=min(dfsLow[u],dfsNum[v]);
	 }
}

int main(){
	while(cin >> n >> m && (n || m)){
		for(int i=0 ; i<MAX+10; i++) dfsLow[i]=parent[i]=dfsNum[i]=0, adj[i].clear();
		artPoints.assign(MAX+10,0); lev=1;//initialization
		
		int u, v;
		while(cin >> u >> v && u!=-1){
			adj[u].push_back(v), adj[v].push_back(u);
		}
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0){
				dfsRoot=i; rootChilds=0; dfs(i);
				artPoints[i] = (rootChilds > 1);
			}
		}

		vector<pii> ans;
		for(int i=0 ; i<n ; i++){
			artPoints[i]++;
			ans.push_back(pii(artPoints[i], i));
		}
		sort(ans.begin(), ans.end(), cmp);
		for(int i=0 ; i < m ; i++){
			cout << ans[i].second << " " << ans[i].first << endl;
		}cout << endl;
		
	}
	return 0;
}
