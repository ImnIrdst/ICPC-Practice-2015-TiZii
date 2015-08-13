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
#define MAX 100000
#define vi  vector< int >
#define vvi vector< vi  >

using namespace std;

int dfsNum[MAX+10],dfsLow[MAX+10],vis[MAX+10], SCCNum[MAX+10], SCCVal[MAX+10];
int n,m,lev,SCCCnt; vi SCC,dp; vvi adj2, adj;

// for SCC
void dfs(int u){
	dfsLow[u]=dfsNum[u]=lev++; vis[u]=1; SCC.push_back(u);
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(dfsNum[v]==0) dfs(v);
		if(vis[v]) dfsLow[u]=min(dfsLow[u], dfsLow[v]);
	}
	if(dfsLow[u]==dfsNum[u]){
		for(int i=0, v ; !SCC.empty() ; i++){
			v=SCC.back(); SCC.pop_back(); vis[v]=0;
			SCCNum[v]=SCCCnt; SCCVal[SCCCnt]++;
			if(v==u) break;
		}
		SCCCnt++;
		//cout << SCCVal[SCCCnt-1] << " ";
	}
}
//for longest path
int dfs2(int u){
	int& dpp = dp[u];
	if(dpp!=-1) return dpp; dpp=0;
	for(int i=0 ; i<adj2[u].size() ; i++){
		int v=adj2[u][i];
		dpp = max(dpp,dfs2(v));
	}
	dpp+=SCCVal[u];
	return dpp;
}

int main(){
	int x,y,tc; cin >> tc;
	while(tc--){cin >> n >> m;
		memset(dfsNum,0,sizeof dfsNum); memset(vis,0,sizeof vis);
		memset(dfsLow,0,sizeof dfsLow); adj.assign(n,vi());
		memset(SCCNum,0,sizeof SCCNum);	lev=1; SCCCnt=0;
		memset(SCCVal,0,sizeof SCCVal);
		for(int i=0, j=0 ; i<m ; i++){
			cin >> x >> y; x--,y--;
			adj[x].push_back(y);
		}
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0) dfs(i);
		}
		adj2.assign(SCCCnt, vi());
		for(int u=0 ; u<n ; u++){
			for(int i=0 ; i<adj[u].size(); i++){
				int v=adj[u][i];
				if(SCCNum[u]!=SCCNum[v]){
					adj2[SCCNum[u]].push_back(SCCNum[v]);
				}
			}
		}
		dp.assign(SCCCnt,-1); int ans=0;
		for(int i=0 ; i<SCCCnt ; i++){
			ans=max(ans,dfs2(i));
		}
		cout << ans << endl;
	}
	return 0;
}
