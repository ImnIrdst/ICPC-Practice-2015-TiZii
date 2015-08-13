#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX 100

using namespace std;

int adj[MAX+10][MAX+10],n,m,s,f;

int main(){
	int t=1, tc; cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i=0 ; i<n ; i++) 
			for(int j=0 ; j<n ; j++) 
				if(i!=j) adj[i][j]=INF; else adj[i][j]=0;
		int x,y;
		while(m--){
			cin >> x >> y; adj[x][y]=adj[y][x]=1;
		}
		cin >> s >> f;
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
				}
			}
		}
		int ans=0;
		for(int i=0 ; i<n ; i++) if(adj[s][i]!=INF && adj[i][f]!=INF) ans=max(ans,adj[s][i]+adj[i][f]);
		printf("Case %d: %d\n",t++ ,ans);
	}
	return 0;
}