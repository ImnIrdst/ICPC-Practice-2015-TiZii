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
#define MAX 25

using namespace std;

typedef enum{N,E,S,W} dir; // N==North,...
struct node
{
	int x, y, col, lev; dir f; // f=face, lev==level, col==color,0==green
	node(){}
	node(int X, int Y, int Col, dir F,int L ){x=X, y=Y; col=Col; lev=L; f=F;}
};

int n, m, tc=1, vis[MAX+10][MAX+10][10][10],dx[4]={-1,0,+1,0},dy[4]={0,+1,0,-1}; 
char a[MAX+10][MAX+10]; node s, t; 

int check(int i, int j, int col, int f){
	if(i<n && i>=0 && j<m && j>=0 && !vis[i][j][col][f] && a[i][j]!='#'){
		 return 1;
	}
	return 0;
}

int bfs(){
	queue<node> q; q.push(s); //vis[s.x][s.y][0][0]=1;
	while(!q.empty()){
		node u=q.front(); q.pop(); 
		if(u.x==t.x && u.y==t.y && u.col==0) return u.lev;
		if(!check(u.x,u.y,u.col,u.f)) continue;
		vis[u.x][u.y][u.col][u.f]=1;
		q.push(node(u.x,u.y,u.col,(dir)((u.f+1)%4),u.lev+1));
		q.push(node(u.x,u.y,u.col,(dir)((u.f+3)%4),u.lev+1));
		q.push(node(u.x+dx[u.f],u.y+dy[u.f],(u.col+1)%5,u.f,u.lev+1));	
	}
	return -1;
}

int main(){
	while( cin >> n >> m && (n || m) ){
		memset(vis,0,sizeof vis);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
				if(a[i][j]=='S') s=node(i,j,0,N,0);
				if(a[i][j]=='T') t=node(i,j,0,N,0);
			}
		}
		int ans=bfs(); if(tc!=1) cout << endl; 
		cout << "Case #" << tc++ << endl;
		if(ans==-1) cout << "destination not reachable" << endl;
		else cout << "minimum time = " << ans << " sec" << endl;
	}
	return 0;
}