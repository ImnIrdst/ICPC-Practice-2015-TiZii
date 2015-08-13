#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std; 

int dx[] = {-1,+1,+0,+0,+0};
int dy[] = {+0,+0,-1,+1,+0};

struct Point {
	double x, y; Point(double x=0, double y=0) :x(x), y(y){}
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};
double cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
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
	H.resize(k);
	return H;
}

double dist(Point a, Point b){
	double dx = fabs(a.x-b.x), dy= fabs(a.y-b.y);
	double mn = min(dx,dy), mx=max(dx,dy);
	return mn*sqrt(2) + mx-mn;
}

int main()
{
	int n; bool first=1;
	while(scanf("%d", &n)==1){
		double x, y; vector<Point> p,CH;
		for(int i=0 ; i<n ; i++){
			scanf("%lf %lf", &x, &y);
			for(int d=0 ; d<5 ; d++){
				p.push_back(Point(x+dx[d],y+dy[d]));
			}
		}
		CH = convex_hull(p);
		double ans = 0;
		for(int i=0 ; i<int(CH.size())-1 ; i++){
			ans+=dist(CH[i],CH[i+1]);
		}
		//cout << dist(Point(0,1), Point(2,0)) << endl;
		//if(!first) printf("\n\n\n"); first=0;
		printf("%.6lf\n", ans); 
	}
}
