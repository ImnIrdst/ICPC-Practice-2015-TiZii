#include <iostream>

using namespace std;

typedef long long int64;

const int64 m = 1000000007;

int64 powMod(int64 b, int64 p){
	if (p == 1) return b%m;

	int64 half = powMod(b, p / 2);
	if (p % 2 == 1) return (((half*half) % m) * b) % m;
	if (p % 2 == 0) return (((half*half) % m));
}

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int64 n; cin >> n;
		cout << powMod(2, n - 1) << endl;
	}
}