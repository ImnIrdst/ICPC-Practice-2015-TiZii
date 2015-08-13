#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <map>
#define INF  (int)1e9
#define MAX  (10+2)
#define MAX2 (50+10)



using namespace std;

typedef pair<int,int> treasure, pii; treasure trs[MAX]; int ntrs;

int adj[MAX][MAX], dp[MAX][1<<MAX], n, m; char board[MAX2][MAX2]; int vis[MAX2][MAX2];

int dx[]={-1,+1, 0, 0,-1,-1,+1,+1};
int dy[]={ 0, 0,-1,+1,-1,+1,-1,+1};

int InRange(int x, int y){
	return (x<n && x>=0 && y<m && y>=0 && board[x][y]!='#'
				   && board[x][y]!='*' && board[x][y]!='~');}

int solve(int pos, int bit){
	int& dpp = dp[pos][bit];
	if(bit == (1<<ntrs)-1) return adj[pos][0];
	if(dpp != (-1)    ) return dpp; dpp=INF;
	for(int i=0 ; i<ntrs ; i++){
		if( !(bit&(1<<i)) ){
			dpp=min(dpp,solve(i,bit|(1<<i))+adj[pos][i]);
		}
	}
	return dpp;
}



map<treasure,int> mp; treasure par;

void bfs(int sx, int sy){
	queue<pii> q; q.push(pii(sx,sy)); vis[sx][sy]=1;
	while(!q.empty()){
		int x=q.front().first, y=q.front().second; q.pop();

		if(!InRange(x,y)) continue;
		if(mp.count(treasure(x,y))) adj[mp[par]][mp[treasure(x,y)]]=vis[x][y]-1;
		//cout << "bfs: " << x << " "  << y << " " << vis[x][y] << endl;
		for(int k=0 ; k<4 ; k++){
			if(InRange(x+dx[k],y+dy[k]) && !vis[x+dx[k]][y+dy[k]]){
				vis[x+dx[k]][y+dy[k]]=vis[x][y]+1; q.push(pii(x+dx[k],y+dy[k]));
			}
		}
	}
}

int main(){
	
	while(cin >> n >> m && (n || m)){
		ntrs=1; mp.clear(); int cnt1=0, cnt2=0;
		trs[0]=treasure(-1,-1); 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> board[i][j]; if(board[i][j]=='!')cnt1++;
			}
		} 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(board[i][j]=='*') for(int k=0 ; k<8 ; k++)
					if(InRange(i+dx[k],j+dy[k])) board[i+dx[k]][j+dy[k]]='#';
				if(board[i][j]=='!') trs[ntrs++]=treasure(i,j), mp[treasure(i,j)]=ntrs-1, cnt2++;
				if(board[i][j]=='@') trs[0     ]=treasure(i,j), mp[treasure(i,j)]=0;
				///cout << board[i][j] ;
			}
			//cout << endl;
		} 
		//cout << trs[0].first << endl;
		//if(trs[0].first==-1){ cout << -1 << endl; continue; }
		for(int i=0 ; i<ntrs ; i++){
			for(int j=0 ; j<ntrs ; j++) adj[i][j]=INF;
			memset(vis,0,sizeof vis); par = trs[i]; bfs(trs[i].first, trs[i].second); 
			//cout << "adj(" << i << ")={"; for(int j=0 ; j<ntrs ; j++) cout << adj[i][j] << ", ";
			//cout << "}" << endl;
		}
		memset(dp, -1, sizeof dp);
		if(solve(0,1)>=INF || cnt2<cnt1) cout << -1 << endl;
		else cout << solve(0,1) << endl;
	}
	return 0;
}