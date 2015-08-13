#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const double pi = 2*acos(0);

int main(){
	double ang, r; string s;
	while(cin >> r >> ang >> s){
		r += 6440;
		if(s == "min") ang/=60;
		if(ang > 180) ang = 360 - ang;
		ang = ang * pi/180;
		double arc    = r*ang;
		double chord  = sqrt(2*r*r*(1-cos(ang))); 
		printf("%.6lf %.6lf\n", arc, chord);
	}
}