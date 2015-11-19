#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1e2 + 10;

int minx = 1e9, maxx = 0, miny = 1e9, maxy = 0, minz = 1e9, maxz = 0;
int vis[MAX][MAX][MAX] = { 0 };
int dx[] = { -1, +1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, +1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, +1 };

bool inRange(int x, int y, int z){
	if (x >= minx && x <= maxx && 
		y >= miny && y <= maxy && 
		z >= minz && z <= maxz) return true;
	return false;
}

int cnt = 0;

bool floodFill(int ssx, int ssy, int ssz, int col){
	stack<int> sx, sy, sz;
	sx.push(ssx), sy.push(ssy), sz.push(ssz);
	vis[ssx][ssy][ssz] = col;

	int x, y, z;
	int xx, yy, zz;
	while (!sx.empty()){
		x = sx.top(); sx.pop();
		y = sy.top(); sy.pop();
		z = sz.top(); sz.pop();
		
		for (int d = 0; d < 6; d++){
			xx = x + dx[d];
			yy = y + dy[d];
			zz = z + dz[d];
			if (inRange(xx, yy, zz) && !vis[xx][yy][zz]){
				sx.push(xx), 
				sy.push(yy), 
				sz.push(zz), 
				vis[xx][yy][zz] = col;
			}
			//if (vis[xx][yy][zz] == 2 && col != 2) return false;
		}
	}
	return true;
}

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		memset(vis, 0, sizeof vis);
		int n, x, y, z; cin >> n;
		if (n == 0){
			cout << 0 << endl; contine;
		}
		minx=1e9, maxx=0, 
		miny=1e9, maxy=0, 
		minz=1e9, maxz=0;
		for (int i = 0; i < n; i++){
			cin >> x >> y >> z; 
			vis[x][y][z] = 1;
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
			minz = min(minz, z);
			maxz = max(maxz, z);
		}
		minx--; maxx++;
		miny--; maxy++;
		minz--; maxz++;
		floodFill(minx, miny, minz, 2);
		
		int ans = 0; 
		for (int i = minx; i <= maxx; i++){
			for (int j = miny; j <= maxy; j++){
				for (int k = minz; k <= maxz; k++){
					if (!vis[i][j][k]){
						ans++; floodFill(i, j, k, 3);
					}
				}
			}
		}
		cout << ans << endl;
	}
}