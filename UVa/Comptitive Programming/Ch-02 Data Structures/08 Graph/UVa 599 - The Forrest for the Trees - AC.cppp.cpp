#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector<  vi > vvi;

const int MAX = 26+10;

vvi adj; vi vis;

int bfs(int u){
	if(vis[u]) return 0; vis[u]=1;
	int ret = 1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v = adj[u][i];
		ret += bfs(v);
	}
	return ret;
}

int main(){
	int tc; cin >> tc; cin.ignore();
	while(tc--){
		string str; adj.assign(MAX,vi());
		while(cin >> str && str[0]=='('){
			adj[str[1]-'A'].push_back(str[3]-'A');
			adj[str[3]-'A'].push_back(str[1]-'A');
		}
		cin >> str; vi v; vis.assign(MAX,0); 
		for(int i=0 ; i<str.length() ; i+=2){
			v.push_back(str[i]-'A');
		}
		int acorns=0, trees=0;
		for(int i=0 ; i<v.size() ; i++){
			int cnt = bfs(v[i]);
			if(cnt == 0) continue;
			if(cnt == 1) acorns++;
			else		 trees++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}
}