#include <iostream>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

struct state{
	int x, y, s;
	state(int x = 0, int y = 0, int s = 0)
		:x(x), y(y), s(s){}
	bool operator<(const state& op) const {
		return (x != op.x ? x > op.x : y < op.y);
	}
};

const int MAX = 1e2 + 10;
int grid[MAX][MAX], n, m;

int dx[] = { +1, +0, -0, +1, +1 };
int dy[] = { +0, +1, -1, -1, +1 };

int inRange(int x, int y){
	return (x <= n && y <= m && x>0 && y > 0);
}

int main(){
	bool first = true;
	while (cin >> n >> m && (n || m)){
		int p = 4 * m;
		memset(grid, 0, sizeof grid);
		for (int i = 0; i < p; i++){
			int x, y; cin >> x >> y; grid[x][y] = 1;
		}
		state start; cin >> start.x >> start.y;
		
		set<state> ans; // no jump
		for (int i = 0; i < 3; i++){
			int xx = start.x + dx[i];
			int yy = start.y + dy[i];
			if (inRange(xx, yy) && !grid[xx][yy])
				ans.insert(state(xx, yy, 1));
		}

		// jumps
		queue<state> q; q.push(start);
		while (!q.empty()){
			state u = q.front(); q.pop();
			for (int i = 0; i < 5; i++){
				int xx = u.x + dx[i];
				int yy = u.y + dy[i];
				int xxx = xx + dx[i];
				int yyy = yy + dy[i];
				if (!inRange(xx, yy) || !inRange(xxx, yyy)) continue;
				if (grid[xx][yy] == 1 && grid[xxx][yyy] == 0){
					state v(xxx, yyy, u.s + 1);
					ans.insert(v); q.push(v);
				}
			}
		}

		if (!first) cout << endl; first = false;
		
		set<state>::iterator it;
		for (it = ans.begin(); it != ans.end(); it++){
			cout << it->x << " " << it->y << " " << it->s << endl;
		}
	}
}