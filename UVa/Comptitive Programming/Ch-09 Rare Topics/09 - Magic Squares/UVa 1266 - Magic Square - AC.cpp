#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	bool first = true;
	string blankLine = "";
	while (cin >> n){
		
		int map[15][15] = { 0 }, x = 0, y = n / 2;
		for (int i = 0; i < n*n; i++){
			if (map[x][y]){
				x += 2; x = (x + n) % n;
				y--;    y = (y + n) % n;
				map[x][y] = i + 1;
			}
			else map[x][y] = i + 1;
			x--; x = (x + n) % n;
			y++; y = (y + n) % n;
		}

		if (!first) printf("\n"); first = false;
		printf("n=%d, sum=%d\n", n, n*(n*n + 1) / 2);

		if (n*n <= 9){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					printf("%2d", map[i][j]);
				} cout << endl;
			} 
		}
		else if(n*n < 100){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					printf("%3d", map[i][j]);
				} cout << endl;
			}
		}
		else{
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					printf("%4d", map[i][j]);
				} cout << endl;
			}
		}
	}
}