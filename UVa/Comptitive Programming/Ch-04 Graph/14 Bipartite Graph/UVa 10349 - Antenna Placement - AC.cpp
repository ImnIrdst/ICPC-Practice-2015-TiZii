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
#define mp(i,j) (i)*w+j
#define pii pair<int,int>
#define X first
#define Y second

using namespace std;

vector< pii > adj[50][15]; pii owner[50][15];
char b[50][15]; int set[50][15], vis[50][15];
const int S1=1,S2=2,NoS=0; 
int dx[]={ 0, 0,+1,-1};
int dy[]={+1,-1, 0, 0};
int n,h,w;

bool inRange(int x, int y){return (x>=0 && y>=0 && x<h && y<w && b[x][y]=='*');}

void bfs(int x, int y){
	queue< pii > q; q.push(pii(x,y));
	set[x][y]=S1;
	while(!q.empty()){
		x=q.front().X, y=q.front().Y; q.pop();
		for(int i=0 ; i<4 ; i++){
			int x2=x+dx[i] , y2=y+dy[i];
			if(inRange(x2,y2)){
				if(set[x2][y2]==NoS) q.push(pii(x2,y2));
				if(set[x][y]==S1)  set[x2][y2]=S2, adj[x][y].push_back(pii(x2,y2));
				if(set[x][y]==S2)  set[x2][y2]=S1, adj[x2][y2].push_back(pii(x,y));
			}
		}
	}
}

int altpath(pii u){
	if(vis[u.X][u.Y]) return 0;
	vis[u.X][u.Y]=1;
	for(int i=0 ; i<adj[u.X][u.Y].size() ; i++){
		pii v=adj[u.X][u.Y][i];
		if(owner[v.X][v.Y].first==-1 || altpath(owner[v.X][v.Y])){
			owner[v.X][v.Y]=u; return 1;
		}
	}
	return 0;
}

void init(){
	n=0;
	for(int i=0 ; i<50 ; i++){
		for(int j=0 ; j<15 ; j++){
			adj[i][j].clear(); owner[i][j]=pii(-1,-1);
		}
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> h >> w; init();
		for(int i=0 ; i<h ; i++) cin >> b[i];
		for(int i=0 ; i<h ; i++){
			for(int j=0 ; j<w ; j++){
				if(b[i][j]=='*') n++;
			}
		}
		memset(set,0,sizeof set);
		for(int i=0 ; i<h ; i++){
			for(int j=0 ; j<w ; j++){
				if(b[i][j]=='*' && set[i][j]==NoS) bfs(i,j);
			}
		}
		int MCBM=0;
		for(int i=0 ; i<h ; i++){
			for(int j=0 ; j<w ; j++){
				if(b[i][j]=='*' && set[i][j]==S1){
					memset(vis, 0, sizeof vis);
					MCBM+=altpath(pii(i,j));
				}
			}
		}
		cout << n-MCBM << endl;
	}
	return 0;
}