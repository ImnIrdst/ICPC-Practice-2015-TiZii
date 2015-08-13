#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

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

bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}

double ComputeArea(const vector<PT> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(area / 2.0);
}


int main(){
	int n; 
	vector<char> names;
	vector<PT> points, poly; 
	while(cin >> n && n){
		char c; PT pt; points.clear();
		for(int i=0 ; i<n ; i++){
			cin >> c >> pt.x >> pt.y; 
			names.push_back(c), points.push_back(pt);
		}
		double Max=-1; 
		char ans[4]={0}; 
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				for(int k=j+1 ; k<n ; k++){
					poly.clear();
					poly.push_back(points[i]);
					poly.push_back(points[j]);
					poly.push_back(points[k]);
					bool ok = true;
					for(int h=0 ; h<n && ok ; h++){
						if(h==i || h==j || h==k) continue;
						if(PointInPolygon(poly,points[h]) || PointOnPolygon(poly,points[h])) ok=false;
					}
					if(ok && ComputeArea(poly)>Max){
						Max = ComputeArea(poly); ans[0]=names[i], ans[1]=names[j], ans[2]=names[k];
					}
				}
			}
		}
		cout << ans << endl;
	}
}