#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int dcmp(double a, double b) {
	return ((fabs(a - b) < 1e-9) ? 0 : (a < b ? -1 : 1));
}

struct Pt {
	double x, y; 
	Pt(double x = 0, double y = 0) 
		:x(x), y(y) {}
	Pt operator+(const Pt& op) const {
		return Pt(x + op.x, y + op.y);
	}
	Pt operator-(const Pt& op) const {
		return Pt(x - op.x, y - op.y);
	}
	Pt operator*(const double& c) const {
		return Pt(x*c, y*c);
	}
	Pt operator/(const double& c) const {
		return Pt(x/c, y/c);
	}
};

double dist(const Pt& a, const Pt& b) {
	double dx = (a - b).x;
	double dy = (a - b).y;
	return sqrt(dx*dx + dy*dy);
}

vector<Pt> pts;

int main() {
	int tc;
	int cs = 1;
	cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;

		pts.resize(n); 
		double sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
			if (i > 0) sum += dist(pts[i], pts[i - 1]);
		}

		double gap = sum / (m-1), tmpgap=gap;
		
		printf("Road #%d:\n", cs++);
		printf("%.2lf %.2lf\n", pts[0].x, pts[0].y);
		
		int i = 1; 
		Pt last = pts[0];
		while (i < pts.size()) {
			double tmpdist = dist(pts[i], last);
			if (dcmp(dist(pts[i], last), tmpgap)>=0) {
				Pt newpt = pts[i] - last;
				newpt = newpt / tmpdist;
				newpt = newpt * tmpgap; 
				last = last + newpt; tmpgap = gap;
				printf("%.2lf %.2lf\n", last.x, last.y);
			}
			else {
				tmpgap -= dist(pts[i], last);
				last = pts[i]; i++;
			}
		}
		printf("\n");
	}
}