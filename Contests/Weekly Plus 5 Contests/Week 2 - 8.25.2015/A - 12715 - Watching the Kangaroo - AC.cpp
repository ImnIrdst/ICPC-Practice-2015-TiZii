#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 1e5 + 10;

struct interval { int beg, end; 
	interval(int beg = 0, int end = 0): beg(beg), end(end) {}
	bool operator<(const interval& op) const {
		return (beg == op.beg ? end>op.end : beg < op.beg);
	}
}intrvl[MAX];

struct query { int id, val;
	query(int id = 0, int val = 0) : id(id), val(val) {}
	bool operator<(const query& op) const {
		return (val == op.val ? id<op.id : val < op.val);
	}
}x[MAX];

int ans[MAX], n, m, cs=1;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &intrvl[i].beg, &intrvl[i].end);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &x[i].val); x[i].id = i;
		}

		sort(x, x + m);
		sort(intrvl, intrvl + n);

		int cur = 0;
		for (int i = 1; i < n; i++) {
			if (intrvl[cur].end < intrvl[i].end) {
				cur++; intrvl[cur] = intrvl[i];
			}
		}
		cur++;
		n = cur;
		cur = 0;
		for (int i = 0; i < m; i++) {
			int xx = x[i].val;
			int id = x[i].id;
			int& anss = ans[id] = 0;

			if (cur >= n) cur = n - 1;
			for (cur = cur; cur < n; cur++) {
				if (intrvl[cur].beg >= xx) break;
				if (intrvl[cur].end <= xx) continue;
				
				int coverage  = min(xx - intrvl[cur].beg, intrvl[cur].end - xx);
				if (coverage >= anss) anss = coverage;
				else break;
			}
			cur-=3; if (cur < 0) cur = 0; // Margin of safety
		}

		printf("Case %d:\n", cs++);
		for (int i = 0; i < m; i++) {
			printf("%d\n", ans[i]);
		}
	}
}