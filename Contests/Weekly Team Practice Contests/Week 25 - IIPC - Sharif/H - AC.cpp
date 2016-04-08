#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

#define	M_PI	acos(-1)

struct PT {
	double x, y;
	PT(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y)    {}
	PT operator + (const PT &p)  const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p)  const { return PT(x - p.x, y - p.y); }
	bool operator<(const PT &p)  const { return (x != p.x ? x<p.x : y<p.y); }
	PT operator * (double c)     const { return PT(x*c, y*c); }
	PT operator / (double c)     const { return PT(x / c, y / c); }
};

struct Line{
	PT point;
	double m;
	Line(PT point = PT(), double m = 0.0)
		: point(point), m(m) {}
	Line(PT p1, PT p2){
		point = p1;
		if (fabs(p1.x - p2.x) <= EPS) m = INF;
		else{
			m = (p1.y - p2.y) / (p1.x - p2.x);
		}
	}

	bool IsPrep() const{
		return fabs(m - INF) <= EPS;
	}

	bool IsHoriz() const{
		return fabs(m) <= EPS;
	}

	double f(double x) const{
		return point.y + m*(x - point.x);
	}

	PT InterSect(const Line& op) const{
		if (fabs(m - op.m) <= EPS) return PT(INF, INF);//parallel line
		//degenerate cases
		if (IsPrep()) { return PT(point.x, op.f(point.x)); }
		if (op.IsPrep()) { return PT(op.point.x, f(op.point.x)); }
		//general case
		double m1 = m;
		double c1 = point.y - m*point.x;
		double m2 = op.m;
		double c2 = op.point.y - op.m*op.point.x;

		double x_int = (c1 - c2) / (m2 - m1);
		double y_int = f(x_int);

		return PT(x_int, y_int);
	}
};

double dot(PT p, PT q)     { return p.x*q.x + p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p - q, p - q); }
double cross(PT p, PT q)   { return p.x*q.y - p.y*q.x; }

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y, p.x); }
PT RotateCW90(PT p)    { return PT(p.y, -p.x); }
PT RotateCCW(PT p, double t) {
	return PT(p.x*cos(t) - p.y*sin(t), p.x*sin(t) + p.y*cos(t));
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
	vector<PT> ret;
	double d = sqrt(dist2(a, b));
	if (d > r + R || d + min(r, R) < max(r, R)) return ret;
	double x = (d*d - R*R + r*r) / (2 * d);
	double y = sqrt(r*r - x*x);
	PT v = (b - a) / d;
	ret.push_back(a + v*x + RotateCCW90(v)*y);
	if (y > 0)
		ret.push_back(a + v*x - RotateCCW90(v)*y);
	return ret;
}

PT BPoint(const PT& A, const PT& B, const PT& C)
{
	PT mAB = (A + B) / 2;
	PT mBC = (B + C) / 2;
	Line AB(A, B);
	Line BC(B, C);
	Line CA(C, A);
	double prepM;
	
	//fist circle
	if (AB.IsPrep()) prepM = 0;
	else if (AB.IsHoriz()) prepM = INF;
	else prepM = (-1.0 / AB.m);
	Line PrepAB(mAB, prepM);

	if (BC.IsPrep()) prepM = 0;
	else if (BC.IsHoriz()) prepM = INF;
	else prepM = (-1.0 / BC.m);
	Line Bx(B, prepM);

	PT c1_center = PrepAB.InterSect(Bx);
	double c1_rad = sqrt(dist2(c1_center, A));

	//second cirlce
	if (BC.IsPrep()) prepM = 0;
	else if (BC.IsHoriz()) prepM = INF;
	else prepM = (-1.0 / BC.m);
	Line PrepBC(mBC, prepM);
	
	if (CA.IsPrep()) prepM = 0;
	else if (CA.IsHoriz()) prepM = INF;
	else prepM = (-1.0 / CA.m);
	Line Cx(C ,prepM);

	PT c2_center = PrepBC.InterSect(Cx);
	double c2_rad = sqrt(dist2(c2_center, B));

	//circle intersections
	vector<PT> intSet = CircleCircleIntersection(c1_center, c2_center, c1_rad, c2_rad);

	//check which one is the answer???
	return intSet[0];
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--){
		PT A, B, C;
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
		PT ans = BPoint(A, B, C);
		printf("%.5lf %.5lf\n", ans.x , ans.y);
	}
	return 0;
}