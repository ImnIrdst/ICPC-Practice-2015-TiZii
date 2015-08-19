#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long int64;
typedef vector<int64> vi;
typedef vector<vi   > vvi;
map<int, int> mpis;
map<int, int> mpsi;
int64 mod = 1000000007;

vvi matMul(const vvi& a, const vvi& b){
	int n = a.size(); 
	vvi c(n, vi(n, 0));
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				c[i][j] += (a[i][k] * b[k][j])%mod; c[i][j] %= mod;
			}
		}
	}
	return c;
}

vvi base; 

vvi matPow(const vvi& a, int64 n){
	if (n == 1) return base;
	if (n % 2){
		vvi tmp = matPow(a, n - 1);
		return matMul(a, tmp);
	}
	else{
		vvi tmp = matPow(a, n / 2);
		return matMul(tmp, tmp);
	}
}

bool canGo(int i, int j){
	int a = 0;
	int b = 0;
	bool ok = true;
	while (a < 7 && b < 7 && ok){
		while (a < 7 && (((1 << a) & i) == 0)) a++;
		while (b < 7 && (((1 << b) & j) == 0)) b++;
		if (a >= 7 && b >= 7) break;
		if (abs(a - b) == 1) a++, b++;
		else if (a < 6 && b < 6 && a == b &&
			((1 << (a + 1)) & i) && ((1 << (b + 1)) & j)) a += 2, b += 2;
		else ok = false;
	}
	return ok;
}

int ii = 0;
void GraphConstraction(){
	for (int a = 0; a < 7; a++){
		for (int b = a + 1; b < 7; b++){
			for (int c = b + 1; c < 7; c++){
				for (int d = c + 1; d < 7; d++){
					int state = (1 << a) + (1 << b) + (1 << c) + (1 << d);
					mpsi[state] = ii; mpis[ii] = state; ii++;
				}
			}
		}
	}

	base.assign(ii, vi(ii, 0));
	for (int i = 0; i < ii; i++){
		for (int j = 0; j < ii; j++){
			if (canGo(mpis[i], mpis[j])){
				base[j][i] = 1;
			}
		}
	}
}



int main(){
	
	GraphConstraction();
	int tc;
	cin >> tc;
	while (tc--){
		int64 n; cin >> n;
		
		int state = 0;
		for (int i = 0; i < 7; i++){
			int a; cin >> a;
			if (a>0) state |= (1 << i);
		}
		//cout << "# ";
		if (n == 1){
			cout << "1" << endl; continue;
		}

		vvi ret = matPow(base, n - 1);
		int init = mpsi[state];
		
		int64 ans = 0;
		for (int i = 0; i < ii; i++){
			ans += ret[i][init]; ans %= mod;
		}
		cout << ans << endl;

	}
}