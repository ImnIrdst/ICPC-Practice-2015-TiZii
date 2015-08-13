#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int n, m, ans;
int r1, c1, s1;
int r2, c2, s2;
int r3, c3, s3;
int vis[8][8], bfsDist[8][8];

int di []= {-1,+1, 0, 0};
int dj []= { 0, 0,-1,+1};

int inRange(int i, int j){
	return i<n && i>=0 && j<m && j>=0;
}

void bfs(int si, int sj){
	queue<int> qx, qy; qx.push(si); qy.push(sj); 
	memset(bfsDist, -1, sizeof bfsDist); bfsDist[si][sj]=0;

	while(!qx.empty()){
		int x = qx.front(), y = qy.front(); qx.pop(), qy.pop();

		for(int i=0 ; i<4 ; i++){
			int xx = x + di[i], yy = y + dj[i];
			if(!inRange(xx, yy) || vis[xx][yy] || bfsDist[xx][yy]!=-1) continue;

			qx.push(xx), qy.push(yy); bfsDist[xx][yy]=bfsDist[x][y]+1;
		}
	}
}

void solve(int i, int j, int lev){
	if(i == 0 && j == 1){
		if(lev == m*n) ans++; return;
	}
	bfs(i,j);
	if(i == r1 && j == c1 && lev != s1) return;
	if(i == r2 && j == c2 && lev != s2) return;
	if(i == r3 && j == c3 && lev != s3) return;
	if(lev == s1 && (i != r1 || j != c1)) return;
	if(lev == s2 && (i != r2 || j != c2)) return;
	if(lev == s3 && (i != r3 || j != c3)) return;
	if(lev <  s1 && bfsDist[r1][c1] > (s1-lev)) return;
	if(lev <  s2 && bfsDist[r2][c2] > (s2-lev)) return;
	if(lev <  s3 && bfsDist[r3][c3] > (s3-lev)) return;
	if(bfsDist[0][1] == -1) return;

	int urgent=0, urId=-1;
	for(int k=0 ; k<4 ; k++){
		int ii = i + di[k], jj = j + dj[k];
		if(!inRange(ii, jj) || vis[ii][jj] || (ii==0 && jj==1)) continue;

		int neighbors = 0;
		for(int i=0 ; i<4 ; i++){
			int iii = ii + di[i], jjj = jj + dj[i];
			if(!inRange(iii,jjj) || vis[iii][jjj]) continue;
			neighbors++;
		}
		if(neighbors == 0) return;
		if(neighbors == 1) urgent++, urId=k;
	}

	if(urgent > 1) return;
	else if(urgent == 1){
		vis[i+di[urId]][j+dj[urId]] = true;
		solve(i+di[urId],j+dj[urId], lev+1);
		vis[i+di[urId]][j+dj[urId]] = false; return;
	}

	for(int k=0 ; k<4 ; k++){
		int ii = i + di[k], jj = j + dj[k];
		if(!inRange(ii, jj) || vis[ii][jj]) continue;
		vis[ii][jj] = true;
		solve(ii, jj, lev+1);
		vis[ii][jj] = false;
	}
}

int main(){ int cs=1;
	while(cin >> n >> m && (n||m)){
		cin >> r1 >> c1; s1 = (1*m*n)/4;
		cin >> r2 >> c2; s2 = (2*m*n)/4;
		cin >> r3 >> c3; s3 = (3*m*n)/4;
		memset(vis, 0, sizeof vis); ans=0;
		vis[0][0] = true; solve(0, 0, 1);
		cout << "Case " << cs++ << ": " << ans << endl;
	}
}