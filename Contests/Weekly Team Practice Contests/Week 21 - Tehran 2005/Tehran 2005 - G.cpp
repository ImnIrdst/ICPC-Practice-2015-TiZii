#include <iostream>
#include <string>
#include <cstring>
#define UR 0
#define DR 1
#define DL 2
#define UL 3

using namespace std;

const int MAX = 1e3 + 10;

int vis[MAX][MAX][4], cnt[MAX][MAX], R, C;

string ddd[] = { "UR" , "DR", "DL",  "UL" };
//           UR  DR  DL  UL
int dy[] = { -1, +1, +1, -1 };
int dx[] = { +1, +1, -1, -1 };

int inRange(int y, int x){
	return (y >= 0 && y < R && x >= 0 && x < C);
}
int inCorner(int y, int x){
	if (x == 0 && y == 0) return true;
	if (x == 0 && y == R - 1) return true;
	if (x == C - 1 && y == 0) return true;
	if (x == C - 1 && y == R - 1) return true;
	return false;
}

int inEdge(int y, int x){
	return (y == 0 ||  y == R-1 || x == 0 || x == C-1);
}

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		cin >> R >> C;
		int y; cin >> y; y--;
		int x; cin >> x; x--;
		string dir; cin >> dir;
		
		int d;
		if (dir == "UR") d = 0;
		if (dir == "DR") d = 1;
		if (dir == "DL") d = 2;
		if (dir == "UL") d = 3;
		memset(vis, 0, sizeof vis);
		memset(cnt, 0, sizeof cnt);

		int first = true;
		//if (inEdge(y, x) && ){
		//	d = (d + 2) % 4; first = true;
		//	if (y == 0 && d == UR) d = DR;
		//	if (y == 0 && d == UL) d = DL;

		//	if (y == R - 1 && d == DR) d = UR;
		//	if (y == R - 1 && d == DL) d = UL;

		//	if (x == 0 && d == UL) d = UR;
		//	if (x == 0 && d == DL) d = DR;

		//	if (x == C - 1 && d == UR) d = UL;
		//	if (x == C - 1 && d == DR) d = DL;
		//	d = (d + 2) % 4;
		//}
		while (true){
			if (vis[y][x][d]) break;
			cnt[y][x]++;
			if (inCorner(y, x) && !first) break; 

			if (inEdge(y, x) && !first){
				if (y == 0 && d == UR) d = DR;
				if (y == 0 && d == UL) d = DL;

				if (y == R - 1 && d == DR) d = UR;
				if (y == R - 1 && d == DL) d = UL;

				if (x == 0 && d == UL) d = UR;
				if (x == 0 && d == DL) d = DR;

				if (x == C - 1 && d == UR) d = UL;
				if (x == C - 1 && d == DR) d = DL;

				if (vis[y][x][d]) break;

				int yy = y + dy[d];
				int xx = x + dx[d];
				int drev = (d + 2) % 4;
				if (!inRange(yy, xx)) break;
				if (vis[yy][xx][drev]) break;
				//vis[x][y][d] = true;
				y = yy;  x = xx;
				continue;
			}

			int yy = y + dy[d];
			int xx = x + dx[d];
			int drev = (d + 2) % 4;
			if (!inRange(yy, xx)) break;
			if (vis[yy][xx][drev]) break;
			vis[y][x][d] = true;
			y = yy;  x = xx;
			first = false;
		}
		int ans = 0;
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				if (cnt[i][j] >= 2) ans++;
			}
		}
		cout << ans << endl;
	}
}

