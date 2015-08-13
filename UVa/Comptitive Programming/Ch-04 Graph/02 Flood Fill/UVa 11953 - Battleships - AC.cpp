#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9
#define MAX 100

using namespace std;

char a[MAX+10][MAX+10]; int n,vis[MAX+10][MAX+10],cnt[MAX+10]; //a -> color

void bfs(int u, int v){
	if(a[u][v]!='x' && a[u][v]!='@') return;
	vis[u][v]=1;
	if(u<n-1 && !vis[u+1][v]) bfs(u+1,v);
	if(u>0 && !vis[u-1][v]) bfs(u-1,v);
	if(v<n-1 && !vis[u][v+1]) bfs(u,v+1);
	if(v>0 && !vis[u][v-1]) bfs(u,v-1);
}


int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		cin >> n; memset(vis,0,sizeof vis); memset(a,-1,sizeof a); memset(cnt,0,sizeof cnt);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j];
			}
		}
		int ans=0;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(!vis[i][j] && a[i][j]=='x'){
					ans++; bfs(i,j);
				}
			}
		}
		printf("Case %d: %d\n",t++,ans);
	}
	return 0;
}