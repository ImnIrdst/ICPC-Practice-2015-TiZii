#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = 2*acos(0);

struct Pt{ double x, y; };

double dist(Pt a, Pt b){
	return hypot(a.x-b.x,a.y-b.y);
}

int main(){
	Pt pt[3];
	while(cin >> pt[0].x >> pt[0].y){
		cin >> pt[1].x >> pt[1].y;
		cin >> pt[2].x >> pt[2].y;

		double a = dist(pt[0], pt[1]);
		double b = dist(pt[1], pt[2]);
		double c = dist(pt[2], pt[0]);
		double s = (a + b + c) / 2;
		double A = sqrt(s * (s-a) * (s-b) * (s-c));
		double R = (a * b * c) / (4 * A);
		printf("%.2lf\n", 2*pi*R);
	}
}