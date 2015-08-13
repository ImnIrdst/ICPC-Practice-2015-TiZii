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
#define MAX (10+5)

using namespace std;

char a[MAX][MAX],lastGoal; int n,t=1,foodCnt,vis[MAX][MAX][26+10],path_cnt[MAX][MAX][26+10];
int dx[]={ 0, 0,-1,+1};
int dy[]={+1,-1, 0, 0};

struct piiii{
	int x,y,dist,c;
	piiii(){} 
	piiii(int X, int Y, int Dist, int C){x=X, y=Y, dist=Dist, c=C;}
};

int inRange(int i, int j){ return (i>=0 && j>=0 && i<n && j<n && a[i][j]!='#'); }

void bfs(int x, int y){
	memset(vis,0,sizeof vis); memset(path_cnt,0,sizeof path_cnt); path_cnt[x][y][0]=1;
	queue<piiii> q; q.push(piiii(x,y,'A'-'A',0)); //char Goal='B';
	while(!q.empty()){
		int x=q.front().x, y=q.front().y, c=q.front().c, dist=q.front().dist; q.pop();
		if(!inRange(x,y) || vis[x][y][c]) continue; vis[x][y][c]=1; 
		//printf("%d %d: %d %c\n", x, y , dist, c+'A' );
		if(a[x][y]==lastGoal){ cout << dist << " " << path_cnt[x][y][c] << endl; return; }

		char c1=c,c2=c, nextGoal='A'+c;
		if(a[x][y]==nextGoal) a[x][y]='.',c2++,nextGoal++;

		for(int i=0 ; i<4 ; i++){
			int x2=x+dx[i], y2=y+dy[i];
			if(inRange(x2,y2) && !vis[x2][y2][c2] && (a[x2][y2]=='.' || a[x2][y2]==nextGoal)){
				path_cnt[x2][y2][c2]+=path_cnt[x][y][c1]; path_cnt[x2][y2][c2]%=20437;
				q.push(piiii(x2,y2,dist+1,c2));
			}
		}
	}
	
	cout << "Impossible" << endl;
}

int main(){
	while(cin >> n && n){
		int x,y; foodCnt=0;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j]; 
				if('A'<=a[i][j] && a[i][j]<='Z') foodCnt++;
				if(a[i][j]=='A') x=i,y=j;
			}
		}
		cout << "Case " << t++ << ": " ;
		lastGoal='A'+foodCnt-1; bfs(x,y);
	}
	return 0;
}