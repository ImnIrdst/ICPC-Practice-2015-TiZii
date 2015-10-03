#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <set>
#define INF (int)1e9

using namespace std;

int q[9], tmpq[9], n = 9, dp[100][9], top = 0, board[64][64];

int check(int idx){
	for (int i = 1; i<idx; i++){
		if (tmpq[i] == tmpq[idx] || (abs(tmpq[i] - tmpq[idx]) == abs(i - idx))) return 0;
	}
	return 1;
}

int posmod(int n, int m){ return (n%m>0 ? n%m : (n%m) + m); }

void solve(int idx){
	if ((idx>0 && (tmpq[idx - 1]<1 || tmpq[idx - 1]>8)) || !check(idx - 1)) return;
	if (idx == n){
		memcpy(dp[top], tmpq, sizeof tmpq); top++;
	}
	for (int i = 1; i<n; i++){
		if (idx == 0 && i>1) return;
		tmpq[idx] = i;
		solve(idx + 1);
	}
}

int main(){
	int k;
	cin >> k;
	solve(0);
	while (k--){
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				cin >> board[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < top; i++){
			int score = 0;
			for (int j = 1; j < n; j++){
				int ii = j - 1, jj = dp[i][j] - 1;
				score += board[ii][jj];
			}
			ans = max(score, ans);
		}

		printf("%5d\n", ans);
	}
}