#include <iostream>

using namespace std;

typedef long long int64;

const int64 MOD = 1e9 + 7;

int main(){
	int64 n, ans = 10; cin >> n;
	if (n <= 10)
		for (int64 i = 1; i < n; i++) ans = (ans*i) % MOD;
	else{
		ans = 1;
		for (int64 i = 1; i <= 10; i++) ans = (ans*i) % MOD;
		for (int64 i = 1; i <= n - 10; i++) ans = (ans*9) % MOD;
	}
		cout << ans << endl;
}