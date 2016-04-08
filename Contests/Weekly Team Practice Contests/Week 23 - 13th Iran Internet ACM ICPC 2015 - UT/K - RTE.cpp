#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int64;
const int64 MAX = 1e6 + 100;

bitset<MAX> isp;// isprime
vector<int64> primes, factors, pfs; //pfs = prime factors, pws = prime powers
vector<int> num; set<int> st;

int n, m, k;

int gcd(int a, int b) {
	if (b == 0) return a; return gcd(b, a%b);
}

int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}

void genprime() {
	isp.set(); isp[0] = isp[1] = 0;
	for (int64 i = 2; i<MAX; i++) {
		if (isp[i]) {
			primes.push_back(i);
			for (int64 j = i*i; j<MAX; j += i)
				isp[j] = 0;
		}
	}
}

void factorize(int n) {
	int64 tmp = n; factors.clear(); pfs.clear(); st.clear();
	int pf, i;
	for (i = 0, pf = 2; pf*pf <= n; i++, pf = primes[i]) {
		int pow = 0;
		while (tmp%pf == 0) {
			pfs.push_back(pf); tmp /= pf;
		}
	}
	if (tmp > 1) pfs.push_back(tmp);
	for (int bit = 0; bit < (1 << pfs.size()); bit++) {
		int mul = 1;
		for (int i = 0; i < pfs.size(); i++) {
			if (bit&(1 << i)) mul *= pfs[i];
		}
		if (!st.count(mul)) {
			st.insert(mul); factors.push_back(mul);
		}
	}
	sort(factors.begin(), factors.end());
}

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; int64 dp[2010][300]; vi vis;

int64 solve(int u, int id) {
	if (u  == n-1 && id == factors.size() - 1) return 1;
	if (u  == n-1 && id != factors.size() - 1) return 0;
	if (id >= factors.size()) return 0;
	if (id < 0) return 0;

	int64& dpp = dp[u][id];
	if (dpp != -1) return dpp;

	dpp = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		int l = lcm(num[v], factors[id]);
		if (k%l == 0) {
			int iid = lower_bound(factors.begin(), factors.end(), l) - factors.begin();
			dpp += solve(v, iid);
		}
	}
	return dpp;
}

int main() {
	genprime();
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k; num.resize(n);
		for (int i = 0; i < n; i++) cin >> num[i];
		
		adj.assign(n, vi()); char c;
		int u, v; string str; factorize(k);
		for (int i = 0; i < m; i++) {
			cin >> str >> str >> str >> str >> str  >> str >> u >> str >> str >> v >> c;
			u--; v--; adj[u].push_back(v);
		}
		memset(dp, -1, sizeof dp);
		cout << solve(0, 1) << endl;
	}
}