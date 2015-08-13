#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

struct pt { double x, y;
	pt(double x = 0, double y = 0) :x(x), y(y) {}
	bool operator<(const pt& p) const {
		return (x == p.x ? y < p.y : x < p.x);
	}
};

typedef vector<double> vd;
typedef vector<vd    > vvd;
vector<pt> pts; vvd dp; int n;

double dist(const pt& a, const pt& b) {
	return hypot(a.x - b.x, a.y - b.y);
}

double solve(int p1, int p2) {
	int v = 1 + max(p1, p2);
	if (v == n - 1) 
		return dist(pts[p1], pts[v]) + dist(pts[v], pts[p2]);
	double& dpp = dp[p1][p2];
	if (dpp < 1e10) return dpp;
	dpp = min(dpp, solve(v, p2) + dist(pts[p1], pts[v]));
	dpp = min(dpp, solve(p1, v) + dist(pts[v], pts[p2]));
	return dpp;
}

int main() {
	while (cin >> n) {
		pts.resize(n); dp.assign(n, vd(n, 1e11));
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
		}
		sort(pts.begin(), pts.end());
		printf("%.2lf\n", solve(0, 0));
	}
}