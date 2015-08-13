#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double EPS = 1e-9;

struct pt{ double x, y;
	pt(double x=0, double y=0): x(x), y(y){}
};

int dcmp(double a, double b){
	if(fabs(a-b)<EPS) return 0;
	else return (a<b ? -1 : +1);
}

double dist(pt a, pt b){
	return hypot(a.x-b.x, a.y-b.y);
}

int main(){
	int n, m; int a;
	while(cin >> n >> a && (n||dcmp(a,0))){
		pt p, c1(0,0), c2(0,a), c3(a,0), c4(a,a);  int m=0;
		for(int i=0 ; i<n ; i++){
			cin >> p.x >> p.y;
			if(dist(p, c1) > a) continue;
			if(dist(p, c2) > a) continue;
			if(dist(p, c3) > a) continue;
			if(dist(p, c4) > a) continue;
			m++;
		}
		printf("%.5lf\n", (double)m*a*a/n);
	}
}