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

typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<double> vd;
typedef vector<vd    > vvd;
vector<pt> pts; vvd dp; vvi path; int n, pa, pb;

double dist(const pt& a, const pt& b) {
	return hypot(a.x - b.x, a.y - b.y);
}

double solve(int p1, int p2) {
	int v = 1 + max(p1, p2);
	if (v == n - 1) 
		return dist(pts[p1], pts[v]) + dist(pts[v], pts[p2]);
	double& dpp = dp[p1][p2];
	if (dpp < 1e10) 
		return dpp;

	if (v == pa) {
		path[p1][p2] = -1;
		return dpp = solve(v, p2) + dist(pts[p1], pts[v]);
	}
	if (v == pb) {
		path[p1][p2] = 1;
		return dpp = solve(p1, v) + dist(pts[v], pts[p2]);
	}
	double ret1 = solve(v, p2) + dist(pts[p1], pts[v]);
	double ret2 = solve(p1, v) + dist(pts[v], pts[p2]);
	if (ret1 < ret2) {
		path[p1][p2] = -1; return dpp = ret1;
	}
	else {
		path[p1][p2] =  1; return dpp = ret2;
	}
	return dpp;
}

int main() {
	int cs = 1;
	while (cin >> n >> pa >> pb && (n||pa||pb)) {
		pts.resize(n); 
		dp.assign(n, vd(n, 1e11));
		path.assign(n, vi(n, 0000));
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
		}
		sort(pts.begin(), pts.end());
		double ans = solve(0, 0);

		vi path1, path2;
		int i = 0, j = 0, id = 1;
		while (id != n - 1) {
			if (path[i][j] == -1) {
				path1.push_back(id);
				i = id, id++;
			}
			if (path[i][j] == 1) {
				path2.push_back(id);
				j = id; id++;
			}
		}

		printf("Case %d: %.2lf\n", cs++, ans);  
		if (path1[0] == 1) {
			printf("0");
			for (int i = 0; i < path1.size(); i++) {
				printf(" %d", path1[i]);
			}
			printf(" %d", n - 1);
			for (int i = (int)path2.size() - 1; i >= 0; i--) {
				printf(" %d", path2[i]);
			}
			printf(" 0\n");
		}
		else {
			printf("0");
			for (int i = 0; i < path2.size(); i++) {
				printf(" %d", path2[i]);
			}
			printf(" %d", n - 1);
			for (int i = (int)path1.size() - 1; i >= 0; i--) {
				printf(" %d", path1[i]);
			}
			printf(" 0\n");
		}
	}
}