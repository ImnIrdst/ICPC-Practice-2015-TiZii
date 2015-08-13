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

double dot  (PT p, PT q)   { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ") "; 
}

bool ccw(PT a, PT b, PT c){
  return cross(b-a,c-a)>0;
}

bool isConvex(const vector<PT> &p) {
  int s = p.size();
  if(p.size()<3) return false;
  bool dir =  ccw(p[0],p[1],p[2]);
  //cout << p[0] << p[1] << p[2] << endl;
  for(int i=1 ; i<p.size() ; i++){
    //cout << p[i] << p[(i+1)%s] << p[(i+2)%s] << endl;
    if(ccw(p[i],p[(i+1)%s],p[(i+2)%s])!=dir){
      return false;
    }
  }
  return true;
}


int main(){
	PT p; int n;
	while(cin >> n && n){
		vector<PT> poly;
		for(int i=0 ; i<n ; i++){
      cin >> p.x >> p.y; poly.push_back(p);
    }
    //poly.push_back(poly[0]);
	  cout << (isConvex(poly) ? "No" : "Yes" ) << endl;
	}
}
