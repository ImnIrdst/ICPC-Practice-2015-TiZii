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
#define MAX 25

using namespace std;

int adj[MAX+10][MAX+10],dfsNum[MAX+10],dfsLow[MAX+10],vis[MAX+10],n,m,lev; string name[MAX+10]; vector<int> ans;

void dfs(int u){
	dfsLow[u]=dfsNum[u]=lev++; vis[u]=1; ans.push_back(u);
	for(int v=0 ; v<n ; v++){
		if(adj[u][v]){
			if(dfsNum[v]==0) dfs(v);
			if(vis[v]) dfsLow[u]=min(dfsLow[u], dfsLow[v]);
		}
	}
	if(dfsLow[u]==dfsNum[u]){
		for(int i=0,v ; !ans.empty() ; i++){
			v=ans.back(); ans.pop_back(); vis[v]=0;
			if(i==0) printf("%s", name[v].c_str());
			else printf(", %s", name[v].c_str());
			if(v==u) break;
		}
		printf("\n");
	}
}

int main(){
	int t=1; string str1, str2; map<string,int> mp;
	while(cin >> n >> m && (n||m)){
		memset(dfsNum,0,sizeof dfsNum); memset(adj,0,sizeof adj); 
		memset(dfsLow,0,sizeof dfsLow); mp.clear(); lev=1;
		
		for(int i=0, j=0 ; i<m ; i++){
			cin >> str1 >> str2;
			if(!mp.count(str1)){ name[j]=str1; mp[str1]=j++; }
			if(!mp.count(str2)){ name[j]=str2; mp[str2]=j++; }
			adj[mp[str1]][mp[str2]]=1;
		}
		if(t!=1) printf("\n");
		printf("Calling circles for data set %d:\n",t++);
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0) dfs(i);
		}

	}
	return 0;
}