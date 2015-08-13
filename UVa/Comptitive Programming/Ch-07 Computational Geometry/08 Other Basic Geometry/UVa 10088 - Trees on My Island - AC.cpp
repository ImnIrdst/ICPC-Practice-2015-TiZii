#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#define int64 long long

using namespace std;

struct PT { 
  int64 x, y; 
  PT() {}
  PT(int64 x, int64 y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (int64 c)     const { return PT(x*c,   y*c  ); }
  PT operator / (int64 c)     const { return PT(x/c,   y/c  ); }
};

ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

int64 ComputeSignedArea(const vector<PT> &p) {
  int64 area = 0;
  for(int64 i = 0; i < p.size(); i++) {
    int64 j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area;
}

int64 ComputeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}

int main() {
  int64 n; PT p;
  while(cin >> n && n){
    vector<PT> poly;
    for(int64 i=0 ; i<n ; i++){
      cin >> p.x >> p.y; poly.push_back(p);
    }
    int64 Area = ComputeArea(poly);
    int64 boundry = n;
    for(int64 i=0 ; i<n ; i++){
      p = poly[i]-poly[(i+1)%n]; p.x=abs(p.x); p.y=abs(p.y);
      if(p.x==0) boundry += (p.y-1);
      else if(p.y==0) boundry += (p.x-1);
      else boundry += ((__gcd(p.x,p.y))-1);
    }
    cout << (Area-boundry+2)/2 << endl;
  }
  return 0;
}