#include <iostream>
#include <cmath>
#include <cstdio>
#define pi (2*acos(0))
#define toRad(x) (x*pi/180)

using namespace std;

const double INF = 1e100;
const double EPS = 1e-9;

struct pt   { double x,y;  pt  (double x=0, double y=0):x(x), y(y){} };
struct rect { pt lr,ul;
	rect(pt lr=pt(0,0), pt ul=pt(0,0)){ this->lr=lr; this->ul=ul; } 
}rects[10];

int dcmp(double x){return (fabs(x)>EPS?(x>0?1:-1):0);}

bool inRect(rect rc, pt p){
	return (dcmp(p.x-rc.lr.x)<0 && dcmp(p.x-rc.ul.x)>0
		 && dcmp(p.y-rc.ul.y)<0 && dcmp(p.y-rc.lr.y)>0);
}

int main(){
	int n=0; char c; pt p;
	while(cin >> c && c!='*'){
		cin >> rects[n].ul.x >> rects[n].ul.y;
		cin >> rects[n].lr.x >> rects[n].lr.y; n++;
	}
	int t=1; 
	while(cin >> p.x >> p.y){
		if(!(dcmp(p.x-9999.9)) && !(dcmp(p.y-9999.9))) 
			break;
		bool found=0;
		for(int i=0 ; i<n ; i++){
			if(inRect(rects[i],p)){
				printf("Point %d is contained in figure %d\n", t, i+1);
				found=1;
			}
		}
		if(!found) printf("Point %d is not contained in any figure\n", t);
		t++;
	}

}