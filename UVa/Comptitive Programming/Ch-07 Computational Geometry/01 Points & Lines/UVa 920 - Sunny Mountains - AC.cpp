#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cmath>
#define INF (double)1e9
#define EPS (double)1e-9
#define MAX (100+10)

using namespace std;

struct point{double x,y;
	point(double X, double Y){x=X, y=Y;} point(){}
	bool operator==(point& p){return x==p.x && y==p.y;}
	bool operator<(point& p){
		if(x<p.x) return 1;
		if(x>p.x) return 0;
		return y<p.y;
	}
};

struct line{ double a,b,c;
	line(double A, double B, double C){a=A, b=B, c=C;}
	line(point p1, point p2){
		if(p1.x==p2.x) a=1,b=0,c=-p1.x;
		else{
			a = -(double)(p1.y-p2.y)/(p1.x-p2.x);
			c = -(double)(a*p1.x)-(b*p1.y);
			b = 1;
		}
	}
	line(){}
};

bool areParallel(line l1, line l2){ return fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS; }
bool areSame(line l1, line l2){ return areParallel(l1,l2) && fabs(l1.c-l2.c); }
double Distance(point p1, point p2){ return hypot(p1.x-p2.x,p1.y-p2.y); }
point intersect(line l1, line l2){
	if(areSame(l1,l2) || areParallel(l1,l2)) return point(INF,INF);
	double det = l1.a*l2.b-l1.b*l2.a;
	double x = -(l2.b*l1.c-l1.b*l2.c)/det;
	double y = -(l2.c*l1.a-l1.c*l2.a)/det;
	return point(x,y);
}

point cords[MAX];

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		for(int i=0 ; i<n ; i++) cin >> cords[i].x >> cords[i].y;
		sort(cords,cords+n);
		//for(int i=0 ; i<n ; i++) printf("%lf %lf\n",cords[i].x,cords[i].y);
		double ans=0; double MaxY=0;
		for(int i=n-2 ; i>=0 ; i--){//if cause error just iterate reversly
			//printf("\n%.2lf %.2lf | %.2lf %.2lf | %.2lf ",cords[i].x,cords[i].y, cords[i+1].x, cords[i+1].y, MaxY);
			if(cords[i].y<MaxY) continue;
			point inter; // intersection point
			inter = intersect(line(cords[i+1],cords[i]),line(0,1,-MaxY));
			ans += Distance(inter,cords[i]);
			//printf(" | %.2lf %.2lf | %.2lf ", inter.x, inter.y, Distance(inter,cords[i]));
			MaxY=cords[i].y;
		}
		//printf("\n");
		printf("%.2lf\n", ans);
	}
}
