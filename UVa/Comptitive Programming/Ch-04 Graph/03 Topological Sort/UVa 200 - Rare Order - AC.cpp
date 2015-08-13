#include <iostream>
#include <vector>

using namespace std;

typedef vector< int>  vi;
typedef vector< vi > vvi;

int n, m; vvi adj; vi vis, stk;

void dfs(int u){
	if(vis[u]) return; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);	
	}
	stk.push_back(u);	
}

int main(){
	int n=0; vector<string> vs; string str;
	while(cin >> str && str!="#") vs.push_back(str);
	
	n = vs.size();
	vis.assign(30,1); 
	adj.assign(30,vi());
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			for(int k=0 ; k<vs[i].length() && k<vs[j].length() ; k++){
				vis[vs[i][k]-'A']=0;    vis[vs[j][k]-'A']=0;
				if(vs[i][k]==vs[j][k]) continue;
				adj[vs[i][k]-'A'].push_back(vs[j][k]-'A'); break;
			}
		}	
	}
	
	stk.clear();
	for(int i=0 ; i<n ; i++){
		for(int k=0 ; k<vs[i].length() ; k++){
			if(!vis[vs[i][k]-'A']) dfs(vs[i][k]-'A');
		}	
	}
	
	string ans=""; 
	while(!stk.empty()){
		ans+=char(stk.back()+'A'); stk.pop_back();
	}	
	cout << ans << endl;
}