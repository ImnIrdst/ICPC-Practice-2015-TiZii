#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <cstdio>
#include <cstring>

#define xx first
#define yy second
#define pii pair<int,int>

using namespace std;

char board[100][100];
char parr[100][100];
char dirr[] = {"RLUD"};
int  dist[100][100],n,m;
int  dx[] = {+0,+0,+1,-1};
int  dy[] = {-1,+1,+0,+0};
pii  pre[100][100];


int inRange(int i, int j){
	return (i>=0 && i<=n+1 && j>=0 && j<=m+1);
}

int main(){
	int cs=1;
	while(cin >> m >> n && (m||n)){
		cin.ignore();
		memset(board, ' ', sizeof board);
		for(int i=1 ; i<=n ; i++){
			gets(board[i]+1); board[i][m+1]=' ';
		}
		int x1, y1, x2, y2, pir=1; cout << "Board #" << cs++ << ":" << endl;
		while(cin >> y1 >> x1 >> y2 >> x2 && (x1||y1||x2||y2)){
			memset(dist, -1, sizeof dist);
			memset(parr,'o', sizeof parr);
			queue<pii> q; q.push(pii(x1,y1)); dist[x1][y1]=0;
			while( !q.empty() ){
				if(q.front() == pii(x2,y2)) 
					break;
				int x=q.front().xx, y=q.front().yy; q.pop();
				
				for(int dir=0 ; dir<4 ; dir++){
					int x3 = x+dx[dir];
					int y3 = y+dy[dir];
					if(inRange(x3,y3) 
						&& dist[x3][y3]==-1){
						if(board[x3][y3]!='X' || pii(x3,y3) == pii(x2,y2)){
							dist[x3][y3]=dist[x][y]+1;
							parr[x3][y3]=dirr[dir];
							pre[x3][y3]=pii(x,y);
							q.push(pii(x3,y3));
						}
					}
				}
			}
			cout << "Pair " << pir++ << ": ";
			if(dist[x2][y2]==-1){
				cout << "impossible." << endl; continue;
			}

			int segs = 1; int px=x2, py=y2; char c = parr[px][py];
			for(int x=pre[px][py].xx, y=pre[px][py].yy ; 
				x!=x1 || y!=y1 ; x=pre[px][py].xx, y=pre[px][py].yy){
					if(parr[x][y]!=c) segs++, c=parr[x][y];
					px=x, py=y;
			}
			cout << segs << " segments." << endl;
			
		}
		cout << endl;
	}
}