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
	coord_t x, y, v, l; Point(){}
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

vector<Point> convex_hull(vector<Point>& P)
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
	H.resize(k);
	return H;
}

double Area(const vector<Point> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(area / 2.0);
}

Point pts[MAX], tmp; int n, t=1;

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n; vector<Point> P, CH;
		double x, y, w, h, t, sqArea=0;
		for(int i=0 ; i<n ; i++){
			cin >> x >> y >> w >> h >> t;
			double hs = h*sin(toRad(t     ))/2.0, hc = h*cos(toRad(t     ))/2.0;
			double ws = w*sin(toRad(t+90.0))/2.0, wc = w*cos(toRad(t+90.0))/2.0;

			//dx = (w*cos(ToRad(t))+h*cos(ToRad(90-t)))/2;
			//cout << hs << " " << hc << endl;
			P.push_back(Point(x+hs+ws , y+hc+wc));
			P.push_back(Point(x-hs+ws , y-hc+wc));
			P.push_back(Point(x+hs-ws , y+hc-wc));
			P.push_back(Point(x-hs-ws , y-hc-wc));
			//cout << dist(Point(x+dx,y+dy),Point(x+dx,y-dy))
			//		*dist(Point(x-dx,y+dy),Point(x+dx,y+dy)) << endl;
			//cout << h*w << endl;
			sqArea += h*w;
		}
		CH = convex_hull(P);
		printf("%.1lf %c\n", 100*sqArea/Area(CH), '%');
	}
}
