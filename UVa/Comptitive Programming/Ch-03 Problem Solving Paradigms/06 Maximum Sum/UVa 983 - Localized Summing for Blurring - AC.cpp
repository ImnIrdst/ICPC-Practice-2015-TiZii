#include <iostream>

using namespace std;

const int SIZE = 1e3 + 10;

int x[SIZE][SIZE], y[SIZE][SIZE], s[SIZE][SIZE];

int sum(int i, int j, int ii, int jj) {
	int ret = s[ii][jj];
	if (i != 0) ret -= s[i - 1][jj];
	if (j != 0) ret -= s[ii][j - 1];
	if (i != 0 && j != 0) ret += s[i - 1][j - 1];
	return ret;
}

int main() {
	int n, m; 
	bool first = true;
	while (cin >> n >> m) {
		// get input
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				cin >> x[i][j];
			}
		}

		// calc sum table
		for (int i = 0 ; i < n; i++) {
			for (int j = 0; j < n; j++) {
				s[i][j] = x[i][j];
				if (i != 0) s[i][j] += s[i - 1][j];
				if (j != 0) s[i][j] += s[i][j - 1];
				if (i != 0 && j != 0) s[i][j] -= s[i - 1][j - 1];
			}
		}
		
		// calc output matrix
		int Sum = 0;
		if (!first) cout << endl; first = false;
		for (int i = 0; i < n - m + 1; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				Sum += y[i][j] = sum(i, j, i + m - 1, j + m - 1);	
			}
		}

		// print the output
		
		for (int i = n - m; i >= 0; i--) {
			for (int j = 0;  j < n - m + 1; j++) {
				cout << y[i][j] << endl;
			}
		}cout << Sum << endl;
	}
}