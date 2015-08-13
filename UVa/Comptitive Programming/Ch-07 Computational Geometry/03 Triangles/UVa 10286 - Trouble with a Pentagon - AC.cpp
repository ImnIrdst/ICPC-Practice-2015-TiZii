#include <iostream>
#include <cmath>
#include <cstdio>
#define pi (2*acos(0))
#define toRad(x) (x*pi/180)

using namespace std;

const double INF = 1e100;
const double EPS = 1e-12;

int dcmp(double x){return (fabs(x)>EPS?(x>0?1:-1):0);}

int main(){
	double pSide; 
	while(cin >> pSide){
		double ang1  = (108);
		double ang2  = (108 - 90)/2;
		double ang3  = (180 - ang1 - ang2);
		double ang11 = (90);
		double ang12 = (ang2);
		double ang13 = (180 - ang11 - ang12);
		double ang21 = (90);
		double ang22 = (ang3);
		double ang23 = (180 - ang21 - ang22);
		double temp  = (pSide*sin(toRad(ang12)));
		double sSide1= (pSide*cos(toRad(ang12)));
		double sSide2= (temp/tan(toRad(ang22)));
		double sSide = sSide1+sSide2;
		printf("%.10lf\n", sSide);
	}
}