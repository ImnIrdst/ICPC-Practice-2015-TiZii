#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#define INF (int) 1e6
#define MAX 100
#define pii pair<int,int>
using namespace std;

int n, dfsLow[MAX+10], dfsNum[MAX+10],parent[MAX+10] , lev, dfsRoot,rootChilds;
vector<int> adj[MAX+10]; set<string> artPoints; string name[MAX+10]; map<string,int> mp;

void dfs(int u){
	 dfsLow[u]=dfsNum[u]=lev++;
	 for(int i=0 ; i<adj[u].size() ; i++){
		 int v=adj[u][i];
		 if(dfsNum[v]==0){
			 parent[v]=u;
			 if(u==dfsRoot) rootChilds++;
			 dfs(v);
			 if(dfsLow[v]>=dfsNum[u] && u!=dfsRoot)//u is articulation point
			 	artPoints.insert(name[u]);
			 dfsLow[u]=min(dfsLow[u],dfsLow[v]);
		 }
		 else if(parent[u]!=v)
			 dfsLow[u]=min(dfsLow[u],dfsNum[v]);
	 }
}

int main(){
	string str1, str2; int t=1;
	while(cin >> n && n){
		for(int i=0 ; i<MAX+10; i++) dfsLow[i]=parent[i]=INF, dfsNum[i]=0, adj[i].clear();
		artPoints.clear(); lev=1; int tmp=0,m; mp.clear();
		for(int i=0 ; i<n ; i++){
			cin >> str1;
			mp[str1]=tmp; name[tmp++]=str1; 
		}
		cin >> m;
		for(int i=0 ; i<m ; i++){
			cin >> str1 >> str2;
			adj[mp[str1]].push_back(mp[str2]); adj[mp[str2]].push_back(mp[str1]);
		}
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0){
				dfsRoot=i; rootChilds=0; 
				dfs(i);
				if(rootChilds>=2) artPoints.insert(name[dfsRoot]); 
			}
		}
		if(t!=1) printf("\n");
		printf("City map #%d: %d camera(s) found\n",t++ , artPoints.size());
		if(artPoints.size()!=0){
			set<string>::iterator itr;
			for(itr=artPoints.begin() ; itr!=artPoints.end() ;itr++) printf("%s\n", itr->c_str());
		}
	}
	return 0;
}