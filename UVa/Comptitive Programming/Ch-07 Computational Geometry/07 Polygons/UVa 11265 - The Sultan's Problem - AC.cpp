#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define EPS (1e-9)
#define PI  (2*acos(0))
struct point {
	double x, y;
	point() {}; point(double x, double y):x(x), y(y) {}
	bool operator <(point p) const {
		if (fabs(x - p.x) > EPS) return x < p.x;
		return y < p.y;
	}
	bool operator ==(point p) const {
		return fabs(x - p.x) < EPS && fabs(x - p.y) < EPS;
	}
	point operator-(point p){ return point(x - p.x, y - p.y); }
};

typedef point vec;


double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int) P.size() - 1; i++) {
		x1 = P[i].x;
		x2 = P[i + 1].x;
		y1 = P[i].y;
		y2 = P[i + 1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
	return cross(q-p, r-p) > 0;
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double angle(point a, point o, point b) { // returns angle aob in rad
	vec oa = a-o, ob = b-o;
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}


bool inPolygon(point p, const vector<point> &P) {
	if ((int) P.size() == 0)
		return false;
	double sum = 0; 
	for (int i = 0; i < (int) P.size() - 1; i++) {
		if (ccw(p, P[i], P[i + 1]))
			sum += angle(P[i], p, P[i + 1]);   
		else
			sum -= angle(P[i], p, P[i + 1]);
	} 
	return fabs(fabs(sum) - 2 * PI) < EPS;
}

point lineIntersectSeg(point p, point q, point A, point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> cutPolygon(point a, point b, vector<point> &Q) {
	vector<point> P;
	for (int i = 0; i < (int) Q.size(); i++) {
		double left1 = cross(b-a, Q[i]-a), left2 = 0;
		if (i != (int) Q.size() - 1)
			left2 = cross(b-a, Q[i + 1]-a);
		if (left1 > -EPS)
			P.push_back(Q[i]); // Q[i] is on the left of ab
		if (left1 * left2 < -EPS) // edge (Q[i], Q[i+1]) crosses line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
	}
	if (!P.empty()
			&& (fabs(P.back().x - P.front().x) > EPS
					|| fabs(P.back().y - P.front().y) > EPS))
		P.push_back(P.front()); // make P's first point = P's last point
	return P;
}

int main() {
	int N, W, H, x, y, t = 1;
	vector<point> P;

	while (scanf("%d %d %d %d %d", &N, &W, &H, &x, &y) != EOF) {
		P.clear();
		P.push_back(point(0, 0));
		P.push_back(point(W, 0));
		P.push_back(point(W, H));
		P.push_back(point(0, H));
		P.push_back(point(0, 0));
		point fountain(x, y);

		point p1, p2;
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
			if (ccw(p1, p2, fountain))
				P = cutPolygon(p1, p2, P);
			else
				P = cutPolygon(p2, p1, P);
		}

		printf("Case #%d: %.3lf\n", t++, area(P));
	}
	return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <cmath>
// #include <cassert>
// #define VPoint  vector<Point>
// #define VVPoint vector<VPoint>

// using namespace std;

// double INF = 1e100;
// double EPS = 1e-12;

// struct Point
// {
// 	double x, y;
// 	Point(double x = 0, double y = 0) : x(x), y(y) { }
// 	bool operator < (const Point& a) const
// 	{
// 		if(a.x != x) return x < a.x;
// 		return y < a.y;
// 	}
// };

// typedef Point Vector;

// Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }

// Vector operator - (Point A, Point B) { return Vector(A.x-B.x, A.y-B.y); }

// Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }

// Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }

// ostream &operator<<(ostream &os, const Point &p) {
//   os << "(" << p.x << "," << p.y << ") ";
// }

// int dcmp(double x)
// {
// 	if(fabs(x) < EPS) return 0; else return x < 0 ? -1 : 1;
// }

// bool operator == (const Point& a, const Point &b)
// {
// 	return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
// }

// double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }

// double Length(Vector A) { return sqrt(Dot(A, A)); }

// double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

// double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

// double Area2(Point A, Point B, Point C) { return fabs(Cross(B-A, C-A)) / 2; }

// Vector Rotate(Vector A, double rad)
// {
// 	return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
// }

// Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
// {
// 	Vector u = P-Q;
// 	double t = Cross(w, u) / Cross(v, w);
// 	return P+v*t;
// }

// bool OnSegment(Point p, Point a1, Point a2)
// {
// 	return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
// }

// double PolygonArea(vector<Point> p)
// {
// 	double area = 0; int n=p.size();
// 	for(int i = 1; i < n-1; i++)
// 		area += Cross(p[i]-p[0], p[i+1]-p[0]);
// 	return area/2;
// }

// int isPointInPolygon(Point p, vector<Point> poly)
// {
// 	int wn = 0; int n = poly.size();
// 	for(int i = 0; i < n; i++)
// 	{
// 		const Point& p1 = poly[i], p2 = poly[(i+1)%n];
// 		if(p == p1 || p == p2 || OnSegment(p, p1, p2)) return -1;
// 		int k = dcmp(Cross(p2-p1, p-p1));
// 		int d1 = dcmp(p1.y - p.y);
// 		int d2 = dcmp(p2.y - p.y);
// 		if(k > 0 && d1 <= 0 && d2 > 0) wn++;
// 		if(k < 0 && d2 <= 0 && d1 > 0) wn--;
// 	}
// 	if(wn != 0) return 1;
// 	return 0;
// }

// vector<Point> CutPolygon(const vector<Point> &poly, Point A, Point B){
// 	vector<Point> newpoly;
// 	int n = poly.size();
// 	for(int i = 0; i < n; i++)
// 	{
// 		Point C = poly[i], D = poly[(i+1)%n];
// 		if(dcmp(Cross(B-A, C-A)) >= 0) newpoly.push_back(C);
// 		if(dcmp(Cross(B-A, C-D)) != 0)
// 		{
// 			Point ip = GetLineIntersection(A, B-A, C, D-C);
// 			if(OnSegment(ip, C, D)) newpoly.push_back(ip);
// 		}
// 	}
// 	if(newpoly.empty()) return newpoly;
// 	if(!(newpoly[0]==newpoly.back())) newpoly.push_back(newpoly[0]);
// 	return newpoly;
// }

// bool OnLeft(Point p1, Point p2, Point p)
// {
// 	return Cross(p2-p1, p-p1) > 0;
// }


// int main(){
// 	int n, W, H, x, y, t=1;
// 	while(cin >> n >> W >> H >> x >> y){
// 		VPoint poly;
// 		poly.push_back(Point(0,0));
// 		poly.push_back(Point(0,H));
// 		poly.push_back(Point(W,H));
// 		poly.push_back(Point(W,0));
// 		poly.push_back(Point(0,0));
// 		for(int i=0 ; i<n ; i++){
// 			Point p1, p2; cin >> p1.x >> p1.y >> p2.x >> p2.y;
// 			if(OnLeft(p1,p2,Point(x,y))) poly = CutPolygon(poly,p1,p2);
// 			if(OnLeft(p2,p1,Point(x,y))) poly = CutPolygon(poly,p2,p1);
// 			for(int i=0 ; i<poly.size() ; i++) cout << poly[i] << " ";
// 			cout << endl;
// 		}
// 		printf("Case #%d: %.3lf\n",t++, fabs(PolygonArea(poly)));
// 	}
// }
