#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) { }
	bool operator < (const Point& a) const {
		if(a.x != x) return x < a.x;
		return y < a.y;
	}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }

int dcmp(double x){
	if(fabs(x) < 1e-9) return 0; else return x < 0 ? -1 : 1;
}

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u = P-Q;
	double t = Cross(w, u) / Cross(v, w);
	return P+v*t;
}

bool OnSegment(Point p, Point a1, Point a2){
	return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}


vector<Point> CutPolygon(const vector<Point> &poly, Point A, Point B){
	vector<Point> newpoly;
	int n = poly.size();
	for(int i = 0; i < n; i++){
		Point C = poly[i], D = poly[(i+1)%n];
		if(dcmp(Cross(B-A, C-A)) >= 0) newpoly.push_back(C);
		if(dcmp(Cross(B-A, C-D)) != 0){
			Point ip = GetLineIntersection(A, B-A, C, D-C);
			if(OnSegment(ip, C, D)) newpoly.push_back(ip);
		}
	}
	return newpoly;
}

int main(){
	int n, cs=1;
	while(cin >> n && n){
		vector<Point> poly(n);
		for(int i=0 ; i<n ; i++){
			cin >> poly[i].x >> poly[i].y;
		}
		vector<Point> remain = poly;
		reverse(poly.begin(), poly.end());
		for(int i = 0; i < n; i++){
			Point A = poly[i], B = poly[(i+1)%n];
			remain = CutPolygon(remain, A, B);
		}

		cout << "Floor #" << cs++ << endl;
		if(remain.size() != 0) cout << "Surveillance is possible." << endl;
		if(remain.size() == 0) cout << "Surveillance is impossible." << endl;
		cout << endl;
	}
}