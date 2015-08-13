#include <iostream>
#include <cmath>
#include <cstdio>
#define pi (2*acos(0))

using namespace std;

const double INF = 1e100;
const double EPS = 1e-12;

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

typedef PT VEC;

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

double Length(VEC A) { return sqrt(dot(A, A)); }

VEC Normal(VEC A){
	double L = Length(A); return VEC (-A.y/L, A.x/L);
}

PT GetLineIntersection(PT P, VEC v, PT Q, VEC w){
	VEC u = P-Q;
	double t = cross(w, u) / cross(v, w);
	return P+v*t;
}




PT p[3]; double side[3],A,S,R; int n,t=1;

double CircleRadii(){
	for(int i=0, c=0; i<3 ; i++){
		for(int j=i+1 ; j<3 ; j++){
			side[c++]=sqrt(dist2(p[i],p[j]));
		}
	}
	S = (side[0] + side[1] + side[2]) / 2;
	A = sqrt(S*(S-side[0])*(S-side[1])*(S-side[2]));
	R = (side[0]*side[1]*side[2]) / (4*A);
	return R;
}

PT CircleCenter(){
	PT mid1; mid1.x = (p[0].x+p[1].x)/2; mid1.y = (p[0].y+p[1].y)/2;
	VEC  v1; v1 = p[1]-p[0]; VEC norm1 = Normal(v1);
//cout << norm1.x << " ** " << norm1.y << " "  << endl;
	PT mid2; mid2.x = (p[2].x+p[1].x)/2; mid2.y = (p[2].y+p[1].y)/2;
	VEC  v2; v2 = p[2]-p[1]; VEC norm2 = Normal(v2);
//cout << norm2.x << " ** " << norm2.y << " "  << endl;
	return GetLineIntersection(mid1,norm1,mid2,norm2);
}

int main(){
	while(cin >> n && n){
		for(int i=0 ; i<3 ; i++) cin >> p[i].x >> p[i].y;
		double R      = CircleRadii(); PT C = CircleCenter();
		double offset = atan2(p[0].y-C.y,p[0].x-C.x);
		double theta  = (pi*(360./n))/180.;
		double up=-INF,down=INF,left=INF,right=-INF;
		for(int i=0 ; i<n ; i++){
			PT New = C + VEC(cos(theta*i+offset),sin(theta*i+offset)) * R;
			up    = max(up   ,New.y); down = min(down,New.y);
			right = max(right,New.x); left = min(left,New.x);
		}
		printf("Polygon %d: %.3lf\n", t++, (up-down)*(right-left));
	}
}