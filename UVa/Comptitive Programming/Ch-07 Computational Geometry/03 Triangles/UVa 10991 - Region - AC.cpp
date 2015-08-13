#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = 2*acos(0);

double getArea(double a,double b,double c){
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
 
double getAngle(double a,double b,double c){
    return acos((a*a+b*b-c*c)/(2*a*b));
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        double r1,r2,r3; cin >> r1 >> r2 >> r3;
        double a = r1+r2, b = r2+r3, c = r1+r3;
        double Area = getArea(a,b,c);
        double Sect1 = (PI*r3*r3)*(getAngle(b,c,a)/(2*PI));
        double Sect2 = (PI*r1*r1)*(getAngle(a,c,b)/(2*PI));
        double Sect3 = (PI*r2*r2)*(getAngle(a,b,c)/(2*PI));
        Area-=Sect1+Sect2+Sect3;
        printf("%.6lf\n",Area);
    }
    return 0;
}