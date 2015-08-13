#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <map>
#include <sstream>
#define INF (int)1e9
#define MAX 100

using namespace std;

string a[MAX+10]; int n,m,vis[MAX+10][MAX+10]; //a -> color

int d1[]={-1,-1,-1, 0,0, 1,1,1};
int d2[]={-1, 0, 1,-1,1,-1,0,1};

int inRange(int i, int j){
	return (i<n && i>=0 && j<m && j>=0 );
}

void bfs(int u, int v){
	if(!inRange(u,v)) return;
	if(vis[u][v] || a[u][v]!='@') return;
	
	vis[u][v]=1;
	for(int i=0 ; i<8 ; i++){
		bfs(u+d1[i],v+d2[i]);
	}
}

int main(){
	while(cin >> n >> m && (n||m)){
		memset(vis,0,sizeof vis);// n=0;
		for(int i=0 ; i<n ; i++) cin >> a[i];
		
		int ans=0; 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(!vis[i][j] && a[i][j]=='@' ) bfs(i,j), ans++;	
			}	
		}
		cout << ans << endl;
	}
	return 0;
}