#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

const double pi  = acos(-1);
const double eps = 1e-9;
int dcmp(double x, double y){
	return (fabs(x-y)<eps ? 0 : (x>y ? -1 : 1));
}

struct Boat{
	double x, y, d, s, ssin, ccos;
	Boat(double x=0, double y=0, double d=0, double s=0)
		:x(x), y(y), d(d), s(s){
		ssin = sin(d/180.0*pi); ccos = cos(d/180.0*pi);
	}
};

int n; double r; 

double dist2(Boat& a, Boat& b, double time){
	double ax, ay, bx, by;
    ax = a.x + a.s*a.ssin*time;
    ay = a.y + a.s*a.ccos*time;
    bx = b.x + b.s*b.ssin*time;
    by = b.y + b.s*b.ccos*time;
	return ((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

double collideTime(Boat a, Boat b){
	if(dist2(a, b, 0) <= r*r) return 0;
	double lo=0, hi=1e4;
	while(fabs(lo-hi)>1e-3){ // Ternary Search
		double mid1 = lo + (hi-lo)/3;
		double mid2 = hi - (hi-lo)/3;
		double dis1 = dist2(a,b, mid1);
		double dis2 = dist2(a,b, mid2);
		if(dis1<=dis2) hi=mid2; else lo=mid1;
	}
	if(dist2(a, b, lo) > r*r) return 1e20;
	hi = lo, lo=0;
	while(fabs(lo-hi)>1e-3){
		double mid = (lo+hi)/2;
		double dis = dist2(a,b,mid);
		if(dis > r*r) lo=mid; else hi=mid;
	}
	return lo;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> r;
		double x, y, d, s;
		vector<Boat> boats;
		for(int i=0 ; i<n ; i++){
			cin >> x >> y >> d >> s;
			boats.push_back(Boat(x,y,d,s));
		}

		double ans = 1e100;
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				ans = min(ans, collideTime(boats[i], boats[j]));
			}
		}
		if(ans > 1e10) printf("No collision.\n");
		else		   printf("%.lf\n", ans);
	}
}
