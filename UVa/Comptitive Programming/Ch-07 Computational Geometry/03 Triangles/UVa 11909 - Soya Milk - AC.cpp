#include <iostream>
#include <cmath>
#include <cstdio>
#define pi  (2*acos(0))
#define eps (double)(1e-9)

using namespace std;

double l,w,h,td,tr,h2,l2,v;

int main(){
	while(cin >> l >> w >> h >> td){
		tr = (td*pi)/180;
		h2 = (l *tan(tr));

		if(h2<h){
			tr = (td*pi)/180;
			h2 = (l*tan(tr));
			v  = (l*h*w)-(0.5*h2*l*w);
		}
		else{
			tr = (90-td)*pi/180;
			l2 = (h*tan(tr));
			v  = (0.5*l2*h*w);
		}
		printf("%.3lf mL\n", v);		
	}
}