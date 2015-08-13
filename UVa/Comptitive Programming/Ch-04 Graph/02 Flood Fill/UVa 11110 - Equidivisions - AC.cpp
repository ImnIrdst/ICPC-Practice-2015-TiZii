#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <sstream>
#define INF (int)1e9
#define MAX 100

using namespace std;

int a[MAX+10][MAX+10],n,vis[MAX+10][MAX+10],cnt[MAX+10]; //a -> color

int d[4]={-1,0,1};

void bfs(int u, int v){
	vis[u][v]=1;
	if(u<n && !vis[u+1][v] && a[u][v]==a[u+1][v]) bfs(u+1,v);
	if(u>1 && !vis[u-1][v] && a[u][v]==a[u-1][v]) bfs(u-1,v);
	if(v<n && !vis[u][v+1] && a[u][v]==a[u][v+1]) bfs(u,v+1);
	if(v>1 && !vis[u][v-1] && a[u][v]==a[u][v-1]) bfs(u,v-1);
}

int main(){
	while(cin >> n && n){
		memset(vis,0,sizeof vis); memset(a,-1,sizeof a); memset(cnt,0,sizeof cnt);
		stringstream sin; string str;  cin.ignore();
		 for(int i=1 ; i<=n ; i++){
		 	for(int j=1 ; j<=n ; j++){
		 		a[i][j]=n;
		 	}
		 }
		for(int k=1 ; k<n ; k++){
			getline(cin,str); sin.clear(); sin << str; int i,j;
			while(sin >> i >> j){
				a[i][j]=k;
			}
		}
		bool flag=true;
		for(int i=1 ; i<=n && flag; i++){
			for(int j=1 ; j<=n && flag ; j++){
				if(!vis[i][j]){
					if(cnt[a[i][j]]){flag=false; break;}
					cnt[a[i][j]]++; bfs(i,j);
				}
			}
		}
		cout << (!flag ? "wrong" : "good" ) << endl;
	}
	return 0;
}