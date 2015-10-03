#include <iostream>

using namespace std;

const int MAX = 52 + 10;

int grid[MAX][MAX] = { 0 }, n, m, b, wall_cost;

struct Bumper{
	int v, c; Bumper(int v = 0, int c = 0):v(v), c(c){}
}bmp[MAX*MAX];


enum direction{ RIGHT, UP, LEFT, DOWN };

const int nextDir[4] = {  DOWN, RIGHT, UP, LEFT };
const int dx[]       = {    +1,     0, -1,    0 };
const int dy[]       = {     0,    +1,  0,   -1 };

int main(){
	cin >> m >> n;
	cin >> wall_cost >> b;

	int x, y;
	for (int i = 1; i <= b; i++){
		cin >> x >> y >> bmp[i].v >> bmp[i].c;
		grid[x][y] = i;
	}

	int ans = 0, dir, lifetime;
	while (cin >> x >> y >> dir >> lifetime){
		int val = 0;
		while (--lifetime > 0){
			int xx = x + dx[dir];
			int yy = y + dy[dir];

			if (xx == m || yy == m || yy == 1 || xx == 1){
				lifetime -= wall_cost;
				dir = nextDir[dir]; continue;
			}

			int id = grid[xx][yy];
			if (id != 0){
				lifetime -= bmp[id].c;
				val      += bmp[id].v;
				dir = nextDir[dir]; continue;
			}

			x = xx; y = yy;
		}

		cout << val << endl; ans += val;
	}
	cout << ans << endl;
}
