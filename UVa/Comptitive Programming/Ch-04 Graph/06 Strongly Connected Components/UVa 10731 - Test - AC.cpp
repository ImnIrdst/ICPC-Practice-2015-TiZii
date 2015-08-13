	#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 26

using namespace std;

int dfsNum[MAX+10],dfsLow[MAX+10],vis[MAX+10],present[MAX+10],n,m,lev,cnt; vector<int> SCC,adj[MAX+10]; vector<string> ans;

void dfs(int u){
	dfsLow[u]=dfsNum[u]=lev++; vis[u]=1; SCC.push_back(u);
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(dfsNum[v]==0) dfs(v);
		if(vis[v]) dfsLow[u]=min(dfsLow[u], dfsLow[v]);
	}
	if(dfsLow[u]==dfsNum[u]){ 
		ans.push_back("");
		for(int i=0, v ; !SCC.empty() ; i++){
			v=SCC.back(); SCC.pop_back(); vis[v]=0;
			ans[cnt]+=(v+'A');
			if(v==u) break;
		}
		cnt++; 
	}
}

int main(){
	int t=0;
	while(cin >> n && n){
		memset(dfsNum,0,sizeof dfsNum); for(int i=0 ; i<MAX+10 ; i++) adj[i].clear(); ans.clear();
		memset(dfsLow,0,sizeof dfsLow); memset(vis,0,sizeof vis); memset(present,0,sizeof present);
		lev=1; cnt=0;
		char c1,c2; 
		for(int i=0 ; i<n ; i++){
			string str;
			for(int j=0 ; j<5 ; j++){
				cin >> c2; present[c2-'A']=1;
				str+=c2;
			}
			cin >> c1; //present[c1-'A']=1;
			for(int i=0 ; i<5 ; i++){
				adj[c1-'A'].push_back(str[i]-'A');
			}
		}
		for(int i=0 ; i<26 ; i++){
			if(dfsNum[i]==0 && present[i]) dfs(i);
		}
		for(int i=0 ; i<ans.size() ; i++){
			sort(ans[i].begin(),ans[i].end());
		}
		sort(ans.begin(),ans.end());
		if(t++) cout << endl;
		for(int i=0 ; i<ans.size() ; i++){
			for(int j=0 ; j<ans[i].length() ; j++){
				if(j!=0) cout << " ";
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
