#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>
#define VI vector<int>
#define VVI vector< VI >

using namespace std;

double INF = 1e100;
double EPS = 1e-9 ;

int dcmp(double x){ return (fabs(x)<EPS ? 0 : (x>0 ? 1 : -1) ); }

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
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) {
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}


int main(){
  double c,x,y; PT xa, xb, ya, yb, intr;
  while(cin >> x >> y >> c){

    double lo=0, hi=min(x,y), mid;
    while(fabs(lo-hi)>=EPS){
       mid  = (lo+hi)/2;
       ya   = PT(0,0); xa = PT(mid,0);
       yb   = PT(mid,sqrt(y*y-mid*mid));
       xb   = PT(0  ,sqrt(x*x-mid*mid));
       intr = ComputeLineIntersection(xa, xb, ya, yb);
       if(dcmp(intr.y-c)==1) lo=mid; else hi=mid;
    }
    printf("%.3lf\n", lo);
  }
}
