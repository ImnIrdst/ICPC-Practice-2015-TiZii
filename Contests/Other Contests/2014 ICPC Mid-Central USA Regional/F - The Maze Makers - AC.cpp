#include <iostream>
#include <cstring>
#include <cctype>
#define isLeftOpen(n)   !(n & (1 << 2))
#define isRightOpen(n)  !(n & (1 << 0))
#define isTopOpen(n)    !(n & (1 << 3))
#define isBottomOpen(n) !(n & (1 << 1))

using namespace std;

const int MAX = 50 + 10;

struct Pt{
	int i, j;
	Pt(int i = -1, int j = -1) :i(i), j(j){}
};

int maze[MAX][MAX], vis[MAX][MAX], n, m;

int hex2dec(char c){
	if (isdigit(c)) return c;
	else return 10 + c - 'A';
}
//          top bot right left 
int di[] = { -1, +1, -0, +0 };
int dj[] = { -0, +0, -1, +1 };

int inRange(int i, int j){
	return i < n && i >= 0 && j < m && j >= 0;
}


int ord;
bool isMultiple;
void dfs(int i, int j, int par){
	if (vis[i][j] != -1){
		if(vis[i][j]!=par) 
			isMultiple = true; 
		return;
	}
	vis[i][j] = par+1;
	for (int d = 0; d < 4; d++){
		int ii = i + di[d];
		int jj = j + dj[d];
	
		if (isTopOpen(maze[i][j]) && isBottomOpen(maze[ii][jj])
			&& d == 0 && inRange(ii, jj) && vis[ii][jj] != par) dfs(ii, jj, par + 1);

		if (isBottomOpen(maze[i][j]) && isTopOpen(maze[ii][jj])
			&& d == 1 && inRange(ii, jj) && vis[ii][jj] != par) dfs(ii, jj, par + 1);

		if (isRightOpen(maze[i][j]) && isLeftOpen(maze[ii][jj])
			&& d == 2 && inRange(ii, jj) && vis[ii][jj] != par) dfs(ii, jj, par + 1);

		if (isLeftOpen(maze[i][j]) && isRightOpen(maze[ii][jj])
			&& d == 3 && inRange(ii, jj) && vis[ii][jj] != par) dfs(ii, jj, par + 1);
	}
	i = i;
}

int main(){
	//cout << isTopOpen(7) << endl;
	//cout << isLeftOpen(11) << endl;
	//cout << isRightOpen(14) << endl;
	//cout << isBottomOpen(13) << endl;
	while (cin >> n >> m && (n || m)){
		char c;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> c; maze[i][j] = hex2dec(c);
			}
		}
		Pt s, t;
		for (int i = 0; i < n; i++)
			if (isRightOpen(maze[i][0]))
				if (s.i == -1) s = Pt(i, 0); else t = Pt(i, 0);
		for (int i = 0; i < n; i++)
			if (isLeftOpen(maze[i][m-1]))
				if (s.i == -1) s = Pt(i, m - 1); else t = Pt(i, m - 1);
		for (int j = 0; j < m; j++)
			if (isTopOpen(maze[0][j])) 
				if (s.i == -1) s = Pt(0, j); else t = Pt(0, j);
		for (int j = 0; j < m; j++)
			if (isBottomOpen(maze[n-1][j])) 
				if (s.i == -1) s = Pt(n - 1, j); else t = Pt(n - 1, j);
		ord = 1;
		memset(vis, -1, sizeof vis);
		isMultiple = false; dfs(s.i, s.j, 0);
		if (vis[t.i][t.j] == -1){
			cout << "NO SOLUTION" << endl; continue;
		}

		bool isUnreachable = false;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (vis[i][j] == -1) isUnreachable = true;
			}
		}
		if (isUnreachable == true){
			cout << "UNREACHABLE CELL" << endl; continue;
		}
		if (isMultiple == true){
			cout << "MULTIPLE PATHS" << endl; continue;
		}
		cout << "MAZE OK" << endl;


	}
}