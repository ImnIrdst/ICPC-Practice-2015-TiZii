#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std; 

struct Point {
	int x, y;
 
	bool operator <(const Point &p) const {
		return y < p.y || (y == p.y && x < p.x);
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
	H.resize(k);
	return H;
}

int main(){
	int tc; cin >> tc; 
	cout << tc << endl;
	while(tc--){
		int n; cin >> n;
		vector<Point> poly, CH; Point pt;
		for(int i=0 ; i<n ; i++){
			cin >> pt.x >> pt.y; poly.push_back(pt);
		}

		CH = convex_hull(poly); 
		n =  CH.size(); cout << n << endl;
		
		for(int i=0 ; i<n ; i++){
			//CH.push_back(CH[i]);
			cout << CH[i].x << " " << CH[i].y << endl;
		}
		if(tc) cin >> n, cout << n << endl;
	}
}
