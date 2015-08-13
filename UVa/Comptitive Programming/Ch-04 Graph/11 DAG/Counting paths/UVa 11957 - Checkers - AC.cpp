#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <sstream>
#include <stack>
#define INF (int)1e9
#define MAX (100+10)
#define MOD 1000007
#define pii pair<int,int>
#define BFS(x,y) q.push(pii(x,y))

using namespace std;

char a[MAX][MAX]; int n,ans,vis[MAX][MAX], d[MAX][MAX]; vector< pii > stk;

bool inRange(int x, int y){ return (x>=0 && y>=0 && x<n && y<n); }
void dfs(int x, int y){//topological sort

	if(vis[x][y]==1) return;
	vis[x][y]=1; //print();
	if(inRange(x-1,y-1) && a[x-1][y-1]!='B') dfs(x-1,y-1); 
	if(inRange(x-1,y-1) && a[x-1][y-1]=='B' 
		&& inRange(x-2,y-2) && a[x-2][y-2]!='B') dfs(x-2,y-2); 

	if(inRange(x-1,y+1) && a[x-1][y+1]!='B') dfs(x-1,y+1);  
	if(inRange(x-1,y+1) && a[x-1][y+1]=='B' 
		&& inRange(x-2,y+2) && a[x-2][y+2]!='B') dfs(x-2,y+2); 
	stk.push_back(pii(x,y));
}

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		cin >> n; int x,y;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j]; if(a[i][j]=='W') x=i,y=j;
			}
		}
		memset(d,0,sizeof d); memset(vis,0,sizeof vis);
		ans=0; dfs(x,y); d[x][y]=1;
		while(!stk.empty()){
			int x=stk.back().first, y=stk.back().second; stk.pop_back();
			d[x][y]%=MOD;
			if(inRange(x-1,y-1) && a[x-1][y-1]!='B') d[x-1][y-1]+=d[x][y]; 
			if(inRange(x-1,y+1) && a[x-1][y+1]!='B') d[x-1][y+1]+=d[x][y]; 

			if(inRange(x-1,y+1) && a[x-1][y+1]=='B' 
				&& inRange(x-2,y+2) && a[x-2][y+2]!='B') d[x-2][y+2]+=d[x][y];
			if(inRange(x-1,y-1) && a[x-1][y-1]=='B' 
				&& inRange(x-2,y-2) && a[x-2][y-2]!='B') d[x-2][y-2]+=d[x][y];
		}
		for(int j=0 ; j<n ; j++) ans+=d[0][j];
		printf("Case %d: %d\n",t++,ans%MOD);
	}
}