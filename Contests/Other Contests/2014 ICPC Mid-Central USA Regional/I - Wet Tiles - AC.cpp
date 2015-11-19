#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Pt{
	int x, y;
	Pt(int x = 0, int y = 0) :x(x), y(y){}
	bool operator<(const Pt& op) const {
		return make_pair(x, y) < make_pair(op.x, op.y);
	}
	bool operator==(const Pt& op) const{
		return make_pair(x, y) == make_pair(op.x, op.y);
	}
};

const int MAX = 1e3 + 10;

int vis[MAX][MAX], grid[MAX][MAX], n, m, t;

int dx[] = { -1, +1, -0, +0 };
int dy[] = { -0, +0, -1, +1 };

void addWall(Pt a, Pt b){
	Pt mins = Pt(min(a.x, b.x), min(a.y, b.y));
	Pt maxs = Pt(max(a.x, b.x), max(a.y, b.y));
	if (a.x == b.x){
	
		for (int y = mins.y; y <= maxs.y; y++) grid[y][a.x] = 2; return;
	}
	if (a.y == b.y){
		for (int x = mins.x; x <= maxs.x; x++) grid[a.y][x] = 2; return;
	}

	if (b < a) swap(a, b);
	if (mins == a){
		for (int x = a.x, y = a.y; x <= b.x; x++, y++) grid[y][x] = 2;
	}
	else{
		for (int x = mins.x, y = maxs.y; x <= maxs.x; x++, y--) grid[y][x] = 2;
	}
}

int main(){
	while (cin >> n && n != -1){
		int l, w; cin >> m >> t >> l >> w;
		memset(vis, 0, sizeof vis);
		memset(grid, 0, sizeof grid);
		for (int i = 0; i < m + 2; i++) grid[i][0] = grid[i][n + 1] = 1;
		for (int j = 0; j < n + 2; j++) grid[0][j] = grid[m + 1][j] = 1;
		
		queue<Pt> q; int x, y;
		for (int i = 0; i < l; i++){
			cin >> x >> y; vis[y][x] = 1; q.push(Pt(x, y));
		}

		Pt a, b;
		for (int i = 0; i < w; i++){
			cin >> a.x >> a.y >> b.x >> b.y; addWall(a, b);
		}

		while (!q.empty()){
			Pt  u = q.front(); q.pop();
			int dist = vis[u.y][u.x];
			for (int d = 0; d < 4; d++){
				Pt v(u.x + dx[d], u.y + dy[d]);
				if (!vis[v.y][v.x] && !grid[v.y][v.x] && dist < t){
					vis[v.y][v.x] = dist + 1; q.push(v);
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < m+2; i++){
			for (int j = 0; j < n+2; j++){
				if (vis[i][j] > 0) cnt++;
			}
		}
		
		cout << cnt << endl;
	}
}