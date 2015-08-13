#include <iostream>
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

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

bool PointInRect(PT p, PT tl, PT br){
  double MaxX = max(tl.x,br.x), MinX = min(tl.x,br.x);
  double MaxY = max(tl.y,br.y), MinY = min(tl.y,br.y);
  return (p.x<=MaxX && p.x>=MinX
       && p.y<=MaxY && p.y>=MinY);
}

int main(){
  PT start, end, topLeft, botRight;
  int tc; cin >> tc;
  while(tc--){
    cin >> start.x   >> start.y   >> end.x >> end.y;
    cin >> topLeft.x >> topLeft.y >> botRight.x >> botRight.y;
    
    bool ans=0;
    ans |= SegmentsIntersect(start, end, botRight, PT(botRight.x,topLeft.y));
    ans |= SegmentsIntersect(start, end, botRight, PT(topLeft.x,botRight.y));
    ans |= SegmentsIntersect(start, end, topLeft , PT(botRight.x,topLeft.y));
    ans |= SegmentsIntersect(start, end, topLeft , PT(topLeft.x,botRight.y));
    ans |= PointInRect(start, topLeft, botRight);
    ans |= PointInRect(end  , topLeft, botRight);
    cout << (ans ? 'T' : 'F') << endl;
  }
}