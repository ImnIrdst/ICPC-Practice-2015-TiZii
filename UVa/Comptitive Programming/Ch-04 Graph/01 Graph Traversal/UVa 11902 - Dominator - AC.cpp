#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <vector>
#define INF (int)1e9
#define MAX 100

using namespace std;

vector<int> adj[MAX+10]; int vis[MAX+10],n,tmpvis[MAX+10];// vis == visited
void bfs(int u, int vis[]){
	if(vis[u]!=0) return; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(vis[v]==0){
			bfs(v,vis);
		}
	}
}

void println(){
	printf("+");
	for(int i=0 ; i<n*2-1 ; i++) printf("-"); 
	printf("+\n");
}
void printsol(){
	printf("|"); for(int i=0 ; i<n ; i++) printf("%c|", (vis[i]==1 && (tmpvis[i]==0 || tmpvis[i]==2 )? 'Y' : 'N') ); printf("\n");
}

int main(){
	int tc,t=1,tmp; cin >> tc;
	while(tc--){
		for(int i=0 ; i<MAX+10 ; i++) adj[i].clear(), vis[i]=0; cin >> n;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> tmp; if(tmp) adj[i].push_back(j);
			}
		}
		printf("Case %d:\n",t++); println(); bfs(0,vis);
		for(int i=0 ; i<n ; i++){
			memset(tmpvis,0,sizeof tmpvis);
			tmpvis[i]=2; bfs(0,tmpvis);
		    printsol(); println();
		}
	}
	return 0;
}