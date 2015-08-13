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

double dot  (PT p, PT q)   { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ") "; 
}

bool ccw(PT a, PT b, PT c){
  return cross(b-a,c-a)>0;
}

double ComputeSignedArea(const vector<PT> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}

double ComputeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}

int main(){
	PT p; int tc; cin >> tc;
	while(tc--){
		int n; cin >> n; vector<PT> poly;
		for(int i=0 ; i<n ; i++){
      cin >> p.x >> p.y; poly.push_back(p);
    }
    //poly.push_back(poly[0]); 
    double w; cin >> w;
    double initPer, spent, falling; cin >> initPer >> spent >> falling;
    double Area = ComputeArea(poly)*w; double initwat = initPer*Area/100;
    //cout << Area << " " << initwat << " " <<  initwat - spent + falling  << endl;
    initwat -= spent;
    if(initwat < -EPS){ printf("Lack of water. "); initwat = 0;}
    initwat += falling;
    if(initwat > Area + EPS){ printf("Excess of water. "); initwat=Area;}
    //cout << initwat << endl;
	  printf("Final percentage: %.0lf%c\n", min(100.0,floor((100.0*initwat)/Area)),'%');
	}
}
 