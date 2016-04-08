#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = (int)1e2 + 10;

int g[SIZE][SIZE], n, m;

struct obs{
	int i, j; 
	obs(int i=0, int j=0) : i(i), j(j){}
};

int inRange(int i, int j){
	return (i <= n+1 && i >= 0 && j <= m+1 && j >= 0);
}
///          D    U  L    R
int di[] = { -1, +1, -0, +0 };
int dj[] = { -0, +0, -1, +1 };

vector<obs> obses;

int dirToInt(char dir){
	if (dir == 'D') return 0;
	if (dir == 'U') return 1;
	if (dir == 'L') return 2;
	if (dir == 'R') return 3;
	return 0;
}

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		cin >> n >> m;
		obses.clear();
		for (int i = 0; i <= n + 1; i++){
			for (int j = 0; j <= m + 1; j++){
				g[i][j] = 1;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> g[i][j];
			}
		}
		for (int i = 0; i <= n + 1; i++){
			for (int j = 0; j <= m + 1; j++){
				if (g[i][j] == 1){
					obses.push_back(obs(i, j));
				}
			}
		}
		int s, e; char dir;
		while (cin >> s >> e && (s && e)){
			cin >> dir;	dir = dirToInt(dir);
			for (int o = 0; o < obses.size(); o++){
				int i = obses[o].i;
				int j = obses[o].j;
				for (int ss = 0; ss < s; ss++){
					i += di[dir];
					j += dj[dir];
					if (!inRange(i, j)) break;
					if (g[i][j] == 1) continue;
					g[i][j] = 2;

					i = i;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n + 1; i++){
			for (int j = 0; j <= m + 1; j++){
				if (g[i][j] == 0) ans++;
			}
		}
		cout << ans << endl;
	}
}