#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdio>

using namespace std;

double INF = 1e100;
double eps = 1e-7/3;

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
  bool operator==(const PT& p) const { return x==p.x && y==p.y; }
  bool operator <(const PT& p) const { return (x!=p.x ? x<p.x : y<p.y);}
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }


vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  PT v = (b-a)/d;
  ret.push_back(a+v*x + RotateCCW90(v)*y);
  if (y > 0)
    ret.push_back(a+v*x - RotateCCW90(v)*y);
  sort(ret.begin(), ret.end());
  return ret;
}


int main(){
	PT a, b; double r, R;
	while(cin >> a.x >> a.y >> r >> b.x >> b.y >> R){
		//a.x += (a.x>=0 ? 1 : -1) * eps; 
		//a.y += (a.y>=0 ? 1 : -1) * eps; 
		//b.x += (b.x>=0 ? 1 : -1) * eps; 
		//b.y += (b.y>=0 ? 1 : -1) * eps; 
		r += (r>=0 ? 1 : -1) * eps;
		R += (R>=0 ? 1 : -1) * eps;
		if(a==b && r==R){
			if(fabs(r)<=eps) printf("(%.3lf,%.3lf)", a.x + 1e-4, a.y + 1e-4);
			else             printf("THE CIRCLES ARE THE SAME");
		}
		else{
			vector<PT> intersect = CircleCircleIntersection(a,b,r,R);
			if(intersect.size()==0) printf("NO INTERSECTION");
			for(int i=0 ; i<intersect.size() ; i++){
				printf("(%.3lf,%.3lf)", intersect[i].x + 1e-4, intersect[i].y + 1e-4);
			}
		}
		printf("\n");
	}
}