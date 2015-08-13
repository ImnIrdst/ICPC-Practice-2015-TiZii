#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std; 

struct Point {
	double x, y; Point(double x=0, double y=0): x(x), y(y) {};
	Point operator + (const Point &p)  const { return Point(x+p.x, y+p.y); }
	Point operator * (double c)     const { return Point(x*c,   y*c  ); }
	Point operator / (double c)     const { return Point(x/c,   y/c  ); }
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};
double cross(const Point &O, const Point &A, const Point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P){
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	// Sort points lexicographically
	sort(P.begin(), P.end());
	// Build lower hull
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k); if(H.size()) H.pop_back();
	return H;
}

double ComputeSignedArea(const vector<Point> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}


Point ComputeCentroid(const vector<Point> &p) {
  Point c(0,0);
  double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
  }
  return c / scale;
}


int main(){
	int n; 
	while(cin >> n && n>2){
		vector<Point> poly, CH; Point pt;
		for(int i=0 ; i<n ; i++){
			cin >> pt.x >> pt.y; poly.push_back(pt);
		}

		CH = convex_hull(poly); 
		Point Center = ComputeCentroid(CH);
		printf("%.3lf %.3lf\n", Center.x , Center.y);
	}
}
