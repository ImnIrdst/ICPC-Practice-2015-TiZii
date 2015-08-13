#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9
#define MAX 20

using namespace std;

char a[MAX+10][MAX+10]; int n,m,vis[MAX+10][MAX+10],cnt[MAX+10]; //a -> color
int posMod(int n, int mod){return (n%mod>=0 ? n%mod : n%mod+mod);} char c;


int bfs(int u, int v){
	if(a[u][v]!=c) return 0;
	vis[u][v]=1; int cnt=1;
	if(u<n-1 && !vis[u+1][v]) cnt+=bfs((u+1),v);
	if(u>0 && !vis[u-1][v]) cnt+=bfs((u-1),v);
	if(!vis[u][(v+1)%n]) cnt+=bfs(u,(v+1)%n);
	if(!vis[u][posMod((v-1),n)]) cnt+=bfs(u,posMod((v-1),n));
	return cnt;
}


int main(){
	while(cin >> n >> m){
		memset(vis,0,sizeof vis); memset(a,-1,sizeof a);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
			}
		}
		int i,j; cin >> i >> j; c=a[i][j]; bfs(i,j);
		int ans=0; 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(!vis[i][j] && a[i][j]==c){
					int tmp=bfs(i,j); ans=max(ans,tmp);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}