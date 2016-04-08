#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long int64;

int main(){
	//init
	int64 c[21][21] = { 0 };
	for (int i = 0; i < 21; i++) {
		c[i][0] = 1; c[i][i] = 1; c[i][1] = i;
	}
	for (int i = 2; i < 21; i++) {
		for (int j = 2; j < i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	int64 fact[21]; fact[0] = 1;
	for (int i = 1; i < 21; i++) {
		fact[i] = i*fact[i - 1];
	}
	//
	
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, a[21]; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		
		double ans = 0; int64 m = 0;
		for (int i = 1; i <= n; i++) {
			m += fact[i] * c[n][i];
		}
		for (int bit = 1; bit < (1 << (n)); bit++) {
			int64 sum = 0; int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (bit&(1 << i)) sum += a[i], cnt++;
			} 
			ans += ((fact[cnt])/(double)m)*sum;
		}
		printf("%.6lf\n", ans);
	}
}