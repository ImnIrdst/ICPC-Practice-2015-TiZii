#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;

const int Maxd = 500 + 10;

struct state{ int i, j, t; 
	state(int i=0, int j=0, int t=0):
		i(i), j(j), t(t){}
};

int board[Maxd][Maxd], dist[Maxd][Maxd][4], n, m;
int di[]={-1,-0,+1,+0};
int dj[]={+0,+1,-0,-1};

int inRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

int main(){
	while(cin >> n >> m){
		string str;
		memset(board, 0, sizeof board);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(i==n-1 && j==m-1) break; cin >> str;
				if(str.find('N')!=-1) board[i][j]|=(1<<N);
				if(str.find('E')!=-1) board[i][j]|=(1<<E);
				if(str.find('S')!=-1) board[i][j]|=(1<<S);
				if(str.find('W')!=-1) board[i][j]|=(1<<W);
			}
		}
		state cur;
		memset(dist, -1, sizeof dist); dist[0][0][0]=0;
		queue<state> q; q.push(state(0,0,0));
		while(!q.empty()){
			cur = q.front(); q.pop();
			if(cur.i==n-1 && cur.j==m-1)
				break;
			for(int dir=0 ; dir<4 ; dir++){
				int ii=cur.i+di[dir], jj=cur.j+dj[dir], tshift=(dir-cur.t+4)%4;
				if(!inRange(ii,jj)) continue;
				if(board[cur.i][cur.j]&(1<<tshift)) 
					if(dist[ii][jj][(cur.t+1)%4]==-1)
						q.push(state(ii,jj,(cur.t+1)%4)), 
						dist[ii][jj][(cur.t+1)%4]=dist[cur.i][cur.j][cur.t]+1;
			}
		}
		if(dist[n-1][m-1][cur.t]==-1) cout << "no path to exit" << endl;
		if(dist[n-1][m-1][cur.t]!=-1) cout << dist[n-1][m-1][cur.t] << endl; 
	}
}