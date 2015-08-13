#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdio>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

#define	M_PI	acos(-1)

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

PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}
// tests for checking point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q) {
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

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}

int main(){
	vector<PT> vpt(3);
	while(true){
		int zeros=0;
		double MaxX=-1, MinX=101;
		double MaxY=-1, MinY=101;
		for(int i=0 ; i<3 ; i++){
			cin >> vpt[i].x >> vpt[i].y; 
			MaxX = max(vpt[i].x, MaxX); MinX = min(vpt[i].x, MinX);
			MaxY = max(vpt[i].y, MaxY); MinY = min(vpt[i].y, MinY);
			if(vpt[i].x==0 || vpt[i].y==0) zeros+=2;
		}
		int ans=0; if(zeros==6) return 0;
		for(int x=max(1.0,ceil(MinX))+0.1 ; x<=min(99.0,floor(MaxX))+0.1 ; x++){
			for(int y=max(1.0,ceil(MinY))+0.1 ; y<=min(99.0,floor(MaxY))+0.1 ; y++){
				if(PointOnPolygon(vpt, PT(x,y)) || PointInPolygon(vpt, PT(x,y))){
					ans++;
				}
			}
		}
		printf("%4d\n", ans);
	}
}