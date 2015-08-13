#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

struct point{
	double x,y;  point(){}  point(double X,double Y){x=X, y=Y;}
};

 point getCords(int n){
	int add,x,y; point p(0,0); long long num=0;
	for(y=1, add=1 ; num<n ; y++) add+=2, num+=add;
	
	int mid=num-(add-1)/2;
	if(mid==n) x=0; else x=mid-n; p.x=(x/2.);
	
	double r32=sqrt(3.)/2., odd=(2/3.)*r32, even=(1/3.)*r32;
	if(y>1){
		p.y+=even; p.y+=(y-2)*r32;
		if((x+y)%2) p.y+=odd;
		else p.y+=even;
	}
	return p;
}

int main(){
	int a,b;
	while(cin >> a >> b){
		point p1=getCords(a), p2=getCords(b);
		printf("%.3lf\n", hypot(p1.x-p2.x,p1.y-p2.y));
	}
	return 0;
}