#include <iostream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;
const int64 MAX = 1e4 + 100;

bitset<MAX> isp;// isprime
vector<int64> primes, pfs, pws; //pfs = prime factors, pws = prime powers

void genprime() {
	isp.set(); isp[0] = isp[1] = 0;
	for (int64 i = 2; i<MAX; i++) {
		if (isp[i]) {
			primes.push_back(i);
			for (int64 j = i*i; j<MAX; j += i) isp[j] = 0;
		}
	}
}

int phi(int n) {
	int64 tmp = n, cnt = 0, cop = n, div = 1;
	for (int i = 0, pf = 2; pf*pf <= n; i++, pf = primes[i]) {
		int pow = 0;
		while (tmp%pf == 0) {
			tmp /= pf; pow++;
		}
		if (pow) {
			pfs.push_back(pf), pws.push_back(pow);
			cop -= cop / pf; div *= (pow + 1);
		}
	}
	if (tmp>1) cop -= cop / tmp, div *= (1 + 1);
	return cop;
}

int64 phii[10010];

void init() {
	genprime();
	for (int i = 0; i < 10010; i++) {
		phii[i] = phi(i);
		if (i != 0) phii[i] += phii[i - 1];
	}
}

int main() {
	int tc;
	init();
	cin >> tc;
	while (tc--) {     
		int n; cin >> n;
		cout << 2 + phii[n] - phii[1] << endl;
	}
}