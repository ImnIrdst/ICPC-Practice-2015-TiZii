#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX (15+10)
#define EPS (double)1e-9
#define INF (double)1e100
#define PII (double)2*acos(0)
#define toRad(t) ((t)*PII/180)

using namespace std; 

typedef double coord_t;   // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

int dcmp(double x, double y){
	return (fabs(x-y)<EPS ? 0 : (x>y ? -1 : 1));
}

struct Point {
	coord_t x, y; Point(){}
	Point(coord2_t x, coord2_t y):x(x), y(y){}
	bool operator <(const Point &p) const {
		if(dcmp(x,p.x)!=0) return dcmp(x,p.x)==1;
		if(dcmp(x,p.x)==0) return dcmp(y,p.y)==1;
	}
	Point operator - (const Point &p)  const { return Point(x-p.x, y-p.y); }
};

coord2_t cross(const Point &O, const Point &A, const Point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double dot(Point p, Point q)     { return p.x*q.x+p.y*q.y; }
double dist(Point p, Point q)    { return sqrt(dot(p-q,p-q)); }

vector<Point> convex_hull(vector<Point> P)
{
	if(P.size()<2) return vector<Point>();
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	// Sort Point lexicographically
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
	H.resize(k-1);
	return H;
}

double Area(const vector<Point> p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(area / 2.0);
}

bool PointInPolygon(const vector<Point> p, Point q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || 
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

int main(){
	int n,t=1; Point p; 
	while(cin >> n && n){
		vector<Point> pts, CH;
		for(int i=0 ; i<n ; i++){
			cin >> p.x >> p.y; pts.push_back(p);
		}
		CH = convex_hull(pts); 
		// for(int i=0 ; i<CH.size() ; i++){
		// 	cout << CH[i].x << "," << CH[i].y << "  ";
		// }cout << endl;
		// for(int i=0 ; i<pts.size() ; i++){
		// 	cout << pts[i].x << "," << pts[i].y << "  ";
		// }cout << endl;
		double CHArea = Area(CH), PTArea = Area(pts);
		//cout << CHArea << " " << PTArea << endl;
		printf("Tile #%d\n", t++);
		printf("Wasted Space = %.2lf %%\n\n", 100*(CHArea-PTArea)/CHArea);
	}
	
}
