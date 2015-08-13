#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std; 

struct Point {
	double x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

double dist(Point a, Point b){
	return hypot(a.x-b.x, a.y-b.y);
}

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
	H.resize(k);
	return H;
}

int main(){
	int n, cs=1; Point pt;
	while(cin >> n && n){
		vector<Point> pts, CH;
		for(int i=0 ; i<n ; i++){
			cin >> pt.x >> pt.y; pts.push_back(pt);
		}
		CH = convex_hull(pts); double perimeter=0;
		reverse(CH.begin(), CH.end());
		if(cs!=1) cout << endl;
		cout << "Region #" << cs++ << ":" << endl;
		for(int i=0 ; i<CH.size() ; i++){
			if(perimeter!=0) printf("-");
			printf("(%.1lf,%.1lf)", CH[i].x, CH[i].y); 
			perimeter+=dist(CH[i], CH[(i+1)%CH.size()]);
		}
		printf("\nPerimeter length = %.2lf\n", perimeter);
	}
}
