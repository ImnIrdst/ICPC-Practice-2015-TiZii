#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int SIZE = 100 + 10;

char grid[SIZE][SIZE];
char  vis[SIZE][SIZE];
int di[] = { -1, +1, -0, +0 };
int dj[] = { -0, +0, -1, +1 };

int n, m;
bool inRange(int i, int j){
	return (i < n && j < m && i >= 0 && j >= 0);
}

int dfs(int ii, int jj){
	if (vis[ii][jj] == 'T') return 0;
	vis[ii][jj] = 'T';

	int ret = 1;
	for (int d = 0; d < 4; d++){
		int nii = ii + di[d];
		int njj = jj + dj[d];
		if (inRange(nii, njj) && grid[nii][njj] == '0') ret += dfs(nii, njj);
	}
	return ret;
}

int main(){
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while (tc--){
		int ii, jj; n = 0;
		cin >> ii >> jj; cin.ignore();
		for (int i = 0; gets(grid[i]); i++){
			if (strlen(grid[i]) == 0) break;
			n++;
		} m = strlen(grid[0]);
		memset(vis, 'F', sizeof vis);
		cout << dfs(ii - 1, jj - 1) << endl;
		if (tc) cout << endl;
	}
}