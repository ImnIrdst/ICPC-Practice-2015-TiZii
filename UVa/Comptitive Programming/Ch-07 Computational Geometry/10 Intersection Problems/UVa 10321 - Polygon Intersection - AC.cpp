#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdio>

using namespace std;

double INF = 1e100;
double EPS = 1e-8;

#define M_PI  acos(-1)

int dcmp(double a, double b){
	return fabs(a-b)<EPS ? 0 : (a-b>0 ? 1 : -1);
}

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator<(const PT &p)  const { return (dcmp(x,p.x)!=0 ? x<p.x : y<p.y ); }
  bool operator==(const PT &p) const { return dcmp(x,p.x)==0 && dcmp(y,p.y)==0; }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

// determine if line segment from a to b intersects with 
// line segment from c to d
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

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}


bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}


bool PointInPolygon(const vector<PT> &p, PT q) {
  int i, j, cnt = 0;
    for(i = 0, j = p.size()-2; i < p.size()-1; j = i++) {
        if(p[i].y > q.y != p[j].y > q.y &&
           q.x < (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y) + p[i].x)
           cnt++;
    }
    return cnt&1;
  //bool c = 0; 
  //for (int i = 0; i < p.size()-1 ; i++){
  //  int j = i+1;
  //  if ((p[i].y <= q.y && q.y < p[j].y || 
  //    p[j].y <= q.y && q.y < p[i].y) &&
  //    q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
  //    c = !c;
  //}
  //return c;// || PointOnPolygon(p, q);
}


int main(){
  int n, m; PT pt;
  while(cin >> n && n>2){
    vector<PT> poly1, poly2; 
    for(int i=0 ; i<n ; i++){
      cin >> pt.x >> pt.y; poly1.push_back(pt);
    }poly1.push_back(poly1[0]);

    cin >> m;
    for(int i=0 ; i<m ; i++){
      cin >> pt.x >> pt.y; poly2.push_back(pt);
    }poly2.push_back(poly2[0]);

    vector<PT> ans;
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<m ; j++){
        if(SegmentsIntersect(poly1[i], poly1[i+1], poly2[j], poly2[j+1])){
          ans.push_back(ComputeLineIntersection(poly1[i], poly1[i+1], poly2[j], poly2[j+1]));
        }
      }
    }
    for(int i=0 ; i<n ; i++){
      if(PointInPolygon(poly2,poly1[i])){
      ans.push_back(poly1[i]);
      }
    }
    for(int j=0 ; j<m ; j++){
      if(PointInPolygon(poly1,poly2[j])){
      ans.push_back(poly2[j]);
      }
    }
    if(ans.size()){
      sort(ans.begin(), ans.end());
      int n = unique(ans.begin(), ans.end())-ans.begin();
      cout << n << endl;
      for(int i=0 ; i<n ; i++){
        printf("%.2lf %.2lf\n", ans[i].x, ans[i].y);
      }
    }
    else cout << ans.size() << endl;
  }
}