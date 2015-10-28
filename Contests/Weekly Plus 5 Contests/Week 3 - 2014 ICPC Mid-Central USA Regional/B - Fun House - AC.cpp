#include <iostream>
#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;

const int MAX = 20 + 10;
//            N   E   S   W    
int dx[] = { -1, +0, +1, -0 };
int dy[] = { -0, +1, +0, -1 };

struct Pt{
	int x, y;
	Pt(int x = 0, int y = 0):x(x), y(y){}
	Pt move(int dir){
		return Pt(x + dx[dir], y + dy[dir]);
	}
};

char grid[MAX][MAX]; int face, m, n, cs = 1; Pt ent;

void findEntrace(){
	for (int i = 0; i < m; i++) 
		if (grid[i][0]     == '*') face = E, ent = Pt(i,0);
	for (int i = 0; i < m; i++) 
		if (grid[i][n - 1] == '*') face = W, ent = Pt(i, n-1);
	for (int j = 0; j < n; j++) 
		if (grid[0][j]     == '*') face = S, ent = Pt(0, j);
	for (int j = 0; j < n; j++) 
		if (grid[m - 1][j] == '*') face = N, ent = Pt(m-1, j);
}

void simulate(){
	Pt u = ent;
	u = u.move(face);
	while (true){
		while (grid[u.x][u.y] == '.') u = u.move(face);

		if (grid[u.x][u.y] == 'x'){
			grid[u.x][u.y] = '&'; return;
		}
		if (grid[u.x][u.y] == '/'){
			if (face == N) face = E;
			else if (face == E) face = N;
			else if (face == S) face = W;
			else if (face == W) face = S;
			u = u.move(face);
		}
		if (grid[u.x][u.y] == '\\'){
			if (face == N) face = W;
			else if (face == E) face = S;
			else if (face == S) face = E;
			else if (face == W) face = N;
			u = u.move(face);
		}
	}
}

int main(){
	while (cin >> n >> m && (n||m)){
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		findEntrace(); simulate();
		cout << "HOUSE " << cs++ << endl;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cout << grid[i][j];
			}cout << endl;
		}
	}
}