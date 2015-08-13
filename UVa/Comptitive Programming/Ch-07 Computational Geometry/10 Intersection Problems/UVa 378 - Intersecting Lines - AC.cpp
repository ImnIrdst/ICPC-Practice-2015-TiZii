#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

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

PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// compute distance from c to segment between a and b
double DistancePointLine(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointLine(a, b, c)));
}

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesSame(PT a, PT b, PT c, PT d){
  return (LinesParallel(a,b,c,d) && fabs(DistancePointLine(a,b,c))<EPS);
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}


int main(){
  PT l1a, l1b, l2a, l2b;
  cout << "INTERSECTING LINES OUTPUT" << endl;
  int tc; cin >> tc;
  while(tc--){
    cin >> l1a.x >> l1a.y >> l1b.x >> l1b.y;
    cin >> l2a.x >> l2a.y >> l2b.x >> l2b.y;
    if(LinesSame(l1a,l1b,l2a,l2b)){
      cout << "LINE" << endl;
    }else if(LinesParallel(l1a,l1b,l2a,l2b)){
      cout << "NONE" << endl;
    }
    else{
      PT p = ComputeLineIntersection(l1a,l1b,l2a,l2b);
      cout << "POINT "; printf("%.2lf %.2lf\n", p.x, p.y);
    }
  }
  cout << "END OF OUTPUT" << endl;
}