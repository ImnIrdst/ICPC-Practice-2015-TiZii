#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
using namespace std;

typedef unsigned long long int64;

int64 c_table[101][101];
void ComputeTable()
{
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) c_table[i][j] = 1;
			else c_table[i][j] = c_table[i-1][j] + c_table[i-1][j-1];
		}
	}
}

int main()
{
	ComputeTable();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		int64 ans = 0;
		cin >> n;
		for (int sh = 0; sh <= n / 3 + 1; sh += 2) {
			int lng = (n - sh) / 2;
			if (lng < sh || lng%2) continue;
			ans += c_table[(lng + sh) >> 1][lng >> 1] * c_table[(lng + sh) >> 1][lng >> 1];
		}
		cout << ans << endl;
	}
	return 0;
}