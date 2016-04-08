#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
#include <cstring>

using namespace std;

const long long MAX = (long long)1e5 + 10;

struct pii {
	long long num, id;
	pii(long long num = 0, long long id = 0) :num(num), id(id) {}
	bool operator<(const pii& op) const {
		return make_pair(num, id) < make_pair(op.num, op.id);
	}
	bool operator==(const pii& op) const {
		return make_pair(num, id) == make_pair(op.num, op.id);
	}
};

set<pii> st;
long long v[MAX], used[MAX], ans[MAX];

int main() {
	long long tc;
	cin >> tc;
	while (tc--) {
		long long n; cin >> n;
		long long m; cin >> m;
		long long cap; cin >> cap;
		if (m == 0) {
			cout << 0 << endl; continue;
		}
		for (long long i = 0; i < n; i++) {
			cin >> v[i];
		}
		st.clear();
		sort(v, v + n, ::greater<long long>());
		for (long long i = 0; i < n; i++) {
			st.insert(pii(v[i], i));
		}
		memset(ans, 0, sizeof ans);
		set<pii>::iterator it;
		long long top = 0;
		for (long long i = 0; i < n; i++) {
			if (!st.count(pii(v[i], i))) continue;
			st.erase(pii(v[i], i));
			if (v[i] < cap) {
				it = st.lower_bound(pii(cap - v[i], -(long long)1e6));
				if ((st.size() && it == st.end()) || (it != st.begin() && (cap - v[i]) != it->num)) it--;
				if (it != st.end()) {
					ans[top++] = (it->num * v[i]);
					st.erase(it);
				}
			}
		}
		sort(ans, ans + n, ::greater<long long>());
		long long sum = 0;
		for (long long i = 0; i < m; i++) sum += ans[i];
		cout << sum << endl;
	}
	return 0;
}
