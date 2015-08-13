#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef struct nodep {
	int x,y,s;
}point;
point p[4008004];
point q[4008004];
point Q[4008004];

int maps[2005][2005];
int step[2005][2005];
int d[4][2] = {0,1,0,-1,1,0,-1,0};

int bfs( int n, int m, int Lx, int Ly, int Hx, int Hy )
{
	for ( int i = Lx ; i <= Hx ; ++ i )
	for ( int j = Ly ; j <= Hy ; ++ j )
		step[i][j] = 4008004;
			
	int move = 0,save = 0;
	for ( int i = 0 ; i < n ; ++ i ) {
		Q[save ++] = p[i];
		step[p[i].x][p[i].y] = 0;
	}
	for ( int i = 0 ; i < m ; ++ i )
		step[q[i].x][q[i].y] = -1;
	
	while ( move < save ) {
		point New,now = Q[move ++];
		for ( int i = 0 ; i < 4 ; ++ i ) {
			New.x = now.x + d[i][0];
			New.y = now.y + d[i][1];
			New.s = now.s + 1;
			if ( New.x >= Lx && New.x <= Hx && New.y >= Ly && New.y <= Hy ) {
				if ( step[New.x][New.y] == -1 ) return New.s;
				if ( step[New.x][New.y] > now.s + 1 ) {
					step[New.x][New.y] = now.s + 1;
					Q[save ++] = New;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int n,m;
	while ( scanf("%d",&n) && n ) {
		int lx = 2002,ly = 2002,hx = 0,hy = 0;
		for ( int i = 0 ; i < n ; ++ i ) {
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].s = 0;
			if ( lx > p[i].x ) lx = p[i].x;
			if ( ly > p[i].y ) ly = p[i].y;
			if ( hx < p[i].x ) hx = p[i].x;
			if ( hy < p[i].y ) hy = p[i].y;
		}
		scanf("%d",&m);
		for ( int i = 0 ; i < m ; ++ i ) {
			scanf("%d%d",&q[i].x,&q[i].y);
			q[i].s = -1;
			if ( lx > q[i].x ) lx = q[i].x;
			if ( ly > q[i].y ) ly = q[i].y;
			if ( hx < q[i].x ) hx = q[i].x;
			if ( hy < q[i].y ) hy = q[i].y;
		}
		
		printf("%d\n",bfs( n, m, lx, ly, hx, hy ));
	}
	return 0;
}
//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <string.h>
//#include <algorithm>
//#include <functional>
//#include <vector>
//#include <cmath>
//#include <queue>
//#define INF (int)1e9
//#define MAX 2000
//
//using namespace std;
//
//struct p{
//	int x,y,lev; 
//	p(){} 
//	p(int X, int Y, int LEV){x=X; y=Y; lev=LEV;}
//};
//
//int vis[MAX+10][MAX+10],n,m;
//int dx[4]={-1, 0, 1, 0};
//int dy[4]={ 0, 1, 0,-1};
//
//int check(int x, int y){
//	if(0<=x && x<MAX && 0<=y && y<MAX && vis[x][y]==0)
//		return 1;
//	return 0; 
//}
//
//int bfs(queue<p>& q){
//	while(!q.empty()){
//		int x=q.front().x, y=q.front().y, lev=q.front().lev; q.pop();
//		if(vis[x][y]==-2) return lev;
//		if(!check(x,y)) continue;
//		vis[x][y]=1;
//		for(int i=0 ; i<4 ; i++)
//			q.push(p(x+dx[i],y+dy[i],lev+1));
//	}
//	return -1;
//}
//
//int main(){
//	int x,y;
//	while(scanf("%d", &n) && n){
//		memset(vis,0,sizeof vis); queue<p> q;
//		while(n--){ scanf("%d %d", &x, &y); q.push(p(x,y,0)); } scanf("%d", &m);
//		while(m--){ scanf("%d %d", &x, &y); if(check(x,y)) vis[x][y]=-2; } 
//		cout << bfs(q) << endl;
//	}
//	return 0;
//}