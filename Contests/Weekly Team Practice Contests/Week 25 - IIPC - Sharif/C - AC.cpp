#include <iostream>
#include <vector>

using namespace std;



typedef long long int64;
typedef vector<int64> vi;
typedef vector<vi   > vvi;

const int64 m = 1e9;

void printMat(vvi a) {
	cout << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vvi matMul(vvi a, vvi b) {
	//printMat(a);
	//printMat(b);
	vvi c(2,vi(2,0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j])%m;
			}
		}
	}
	//printMat(c);
	return c;
}

vvi mat; 

vvi matPow(vvi a, int64 n) {
	if (n <= 1) return a;
	
	vvi Pow = matPow(a, n / 2);
	Pow = matMul(Pow, Pow);
	if (n % 2 == 0) {
		return Pow;
	}
	else {
		return matMul(Pow, mat);
	}
}

int main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int64 n; cin >> n;
		mat.assign(2, vi(2, 1)); mat[1][1] = 0;
		vvi ans = matPow(mat, n);
		cout << ans[0][1] << endl;
	}
}