#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX (15+10)
#define EPS (double)1e-9
#define INF (double)1e100

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

double perimeter(vector<Point>& P){
	double ret=0;
	for(int i=0 ; i<(int)P.size()-1 ; i++){
		ret += dist(P[i],P[i+1]);
	}
	return ret;
}

Point pts[MAX], tmp; int n, t=1;

int main(){
	while(cin >> n && n){
		for(int i=0 ;i<n ; i++){
			cin >> tmp.x >> tmp.y >> tmp.v >> tmp.l; pts[i]=tmp;
		}
		double MinCnt=INF, MinVal=INF, ExWood; int Cutted;
		for(int bit=0 ; bit < (1<<n) ; bit++){

			vector<Point> P; double val=0, len=0; int cnt=0;
			for(int i=0 ; i<n ; i++){
				if(bit&(1<<i)) P.push_back(pts[i]);
				else val+=pts[i].v, len+=pts[i].l, cnt++;
			}
			
			vector<Point> CH = convex_hull(P);
			double peri = perimeter(CH);
			//for(int i=0 ; i<CH.size() ; i++) cout << CH[i].x << " " << CH[i].y << ") ";
			//cout  << endl << bit << " " << val << " " << len << " " << peri << endl;
			if(peri<len){
				if(dcmp(MinVal,val)==-1 ||
				  (dcmp(MinVal,val)==0 && dcmp(MinCnt,cnt)==-1)){
					MinCnt = cnt; MinVal = val; 
					ExWood = len - peri; Cutted = bit;
				}
			}
		}
		if(t!=1) cout << endl;
		cout << "Forest " << t++ << endl;
		cout << "Cut these trees:";
		for(int i=0 ; i<n ; i++) if(!(Cutted&(1<<i))) cout << " " << i+1 ;
		printf("\nExtra wood: %.2lf\n", ExWood);
	}
}
