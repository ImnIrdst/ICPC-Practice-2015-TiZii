#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

const double INF = 1e100;
const double EPS = 1e-12;
const int MAX = 10000000;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

PT cords[MAX];

int main(){
	PT p;
	while(cin >> p.x >> p.y){
		int n; cin >> n;
		for(int i=0 ; i<n+1 ; i++) cin >> cords[i].x >> cords[i].y;
		double Min=INF; PT ans;
		for(int i=1 ; i<n+1 ; i++){
			if(Min > DistancePointSegment(cords[i],cords[i-1],p)){
				Min = DistancePointSegment(cords[i],cords[i-1],p);
				ans = ProjectPointSegment(cords[i],cords[i-1],p);
			}
		}

		printf("%.4lf\n%.4lf\n", ans.x, ans.y);
	}
}
