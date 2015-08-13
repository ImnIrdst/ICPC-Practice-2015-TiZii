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
#define MAX2 (8+1)



using namespace std;

typedef pair<int,int> treasure, pii; treasure pawn[MAX]; int npawn;

int adj[MAX][MAX], dp[MAX][1<<MAX], n=8, m=8; char board[MAX2][MAX2]; int vis[MAX2][MAX2];

int dx[]={+1,+1,-1,-1,+2,+2,-2,-2};
int dy[]={-2,+2,-2,+2,-1,+1,-1,+1};

int InRange(int x, int y){
	return (x<n && x>=0 && y<m && y>=0 
				&& board[x][y]!='p' && board[x][y]!='K');}

int solve(int pos, int bit){
	int& dpp = dp[pos][bit];
	if(bit == (1<<npawn)-1) return 0;
	if(dpp != (-1)    ) return dpp; dpp=INF;
	for(int i=0 ; i<npawn ; i++){
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
		for(int k=0 ; k<8 ; k++){
			if(InRange(x+dx[k],y+dy[k]) && !vis[x+dx[k]][y+dy[k]]){
				vis[x+dx[k]][y+dy[k]]=vis[x][y]+1; q.push(pii(x+dx[k],y+dy[k]));
			}
		}
	}
}

int main(){
	int tc, lim; cin >> tc;
	while(tc--){ cin >> lim;
		npawn=1; mp.clear(); int cnt1=0, cnt2=0;
		pawn[0]=treasure(-1,-1); 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> board[i][j];
				if(board[i][j]=='P') pawn[npawn++]=treasure(i,j), mp[treasure(i,j)]=npawn-1, cnt2++;
				if(board[i][j]=='k') pawn[0     ]=treasure(i,j), mp[treasure(i,j)]=0;
			}
		} 
		for(int i=0 ; i<npawn ; i++){
			for(int j=0 ; j<npawn ; j++) adj[i][j]=INF;
			memset(vis,0,sizeof vis); par = pawn[i]; bfs(pawn[i].first, pawn[i].second); 
			//cout << "adj(" << i << ")={"; for(int j=0 ; j<npawn ; j++) cout << adj[i][j] << ", ";
			//cout << "}" << endl;
		}
		memset(dp, -1, sizeof dp);
		if(solve(0,1)<=lim) cout << "Yes" << endl;
		else				cout << "No" << endl;
	}
	return 0;
}