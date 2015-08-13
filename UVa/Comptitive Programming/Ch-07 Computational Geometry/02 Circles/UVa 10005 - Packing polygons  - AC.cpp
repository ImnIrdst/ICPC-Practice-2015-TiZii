#include <iostream>
#include <cmath>
#include <cstdio>


using namespace std;
const int MAX = (100+10);
const double INF = 1e100;
const double EPS = 1e-12;
const double PII = 2*acos(0);

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


PT p[MAX]; double r; int n;

double dot  (PT p, PT q){ return p.x*q.x+p.y*q.y;	}
double dist2(PT p, PT q){ return dot(p-q,p-q);		}

int dcmp(double a, double b){
	 if ( fabs(a - b) < EPS )
		  return 1;
	  return a < b ? 0 : 2;
}

PT circle2PtsRad(PT p1, PT p2, double r){
	double d2 = dist2(p1,p2);
	double det = r*r / d2 - 0.25;
	if(det < 0.0) return PT(INF,INF);
	double h  = sqrt(det);
	double x  = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	double y  = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return PT(x,y);
}

bool check(PT c){
	for(int i=0 ; i<n ; i++){
		if(dcmp(dist2(c,p[i]),r*r)==2) return false;
	}
	return true;
}

int main(){
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++){
			cin >> p[i].x >> p[i].y;
		}
		cin >> r; bool found=0; PT c;
		for(int i=0 ; i<n && !found ; i++){
			for(int j=i+1 ; j<n && !found ; j++){
				c = circle2PtsRad(p[i],p[j],r);
				if(check(c)) found=true;
				
				c = circle2PtsRad(p[j],p[i],r);
				if(check(c)) found=true;
			}
		}
		if(found==1) printf("The polygon can be packed in the circle.\n");
		if(found==0) printf("There is no way of packing that polygon.\n");
	}
}
