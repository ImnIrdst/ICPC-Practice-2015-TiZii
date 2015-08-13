#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <list>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT {
  double x, y; PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

struct Seg{
  PT a, b; int idx; Seg(){}
  Seg(PT a1, PT b1, int i):a(a1), b(b1), idx(i) {}
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

int main(){
  Seg s,cur; int n,k;
  while(cin >> n && n){
    list<Seg> tops; list<Seg>::iterator it;
    for(int i=0 ; i<n ; i++){
      cin >> cur.a.x >> cur.a.y >> cur.b.x >> cur.b.y; cur.idx=i+1;
      for(it=tops.begin() ; it!=tops.end() ; it++){
        if(SegmentsIntersect(cur.a, cur.b, it->a, it->b)){
            it=tops.erase(it); it--;
        }
      }
      tops.push_back(cur);
    }
    cout << "Top sticks:" ;
    for(it=tops.begin(), k=0 ; it!=tops.end() ; k++, it++){
        if(k!=tops.size()-1) cout << " " << it->idx << ",";
        if(k==tops.size()-1) cout << " " << it->idx << ".";
    }
    cout << endl;

  }
}
