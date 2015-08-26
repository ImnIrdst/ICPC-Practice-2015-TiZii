#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10 + 10;

char board[MAX][MAX]; int n;
char touch[MAX][MAX], out[MAX][MAX];

int di[] = { +1,+1,+1,+0,+0,-1,-1,-1};
int dj[] = { +1,+0,-1,+1,-1,+1,+0,-1};

int inRange(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < n);
}

void Touch(int i, int j) {
	
	if (board[i][j] == '*') {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++ ) {
				if (board[x][y] == '*') out[x][y] = '*';
			}
		}
		return;
	}
	else {
		int cnt = 0;
		for (int d = 0; d < 8; d++) {
			if (!inRange(i + di[d], j + dj[d])) continue;
			if (board[i + di[d]][j + dj[d]] == '*') cnt++;
		}
		out[i][j] = '0' + cnt;
	}

}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> board[i];
		for (int i = 0; i < n; i++) cin >> touch[i];
		memset(out, '.', sizeof out);

		bool solved = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (touch[i][j] == 'x') Touch(i, j);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << out[i][j];
			}
			cout << endl;
		}
		if (tc) cout << endl;
	}
}