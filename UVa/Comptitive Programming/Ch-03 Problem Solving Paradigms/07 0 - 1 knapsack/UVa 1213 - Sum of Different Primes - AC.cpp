#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

typedef long long int64;
const int64 MAX = 1e3 + 200;

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

int dp[200][1120+10][14+5], n;

int solve(int id, int num, int rem) {
	if (num == 0 && rem == 0) return 1;
	if (num <  0 || rem <= 0) return 0;
	if (id  >= n) return 0;
	
	int& dpp = dp[id][num][rem];
	if (dpp != -1) return dpp;
	
	dpp = solve(id + 1, num - primes[id], rem - 1) + solve(id + 1, num, rem);
	return dpp;
}

int main() {
	int num, k; genprime();
	while (cin >> num >> k && (num || k)) {
		n = 0; memset(dp, -1, sizeof dp);
		for (int i = 0; i < primes.size(); i++) {
			if (primes[i] <= num) n++; else break;
		}
		cout << solve(0, num, k) << endl;
	}
}

