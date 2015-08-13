#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define P2D pair<int,int>
#define P3D pair<P2D,int>
#define x first.first
#define y first.second
#define z second
#define MAX (5000+10)

using namespace std;

double INF = 1e100;
double EPS = 1e-12;
P3D operator-(P3D a, P3D b)  { return P3D(P2D(a.x-b.x,a.y-b.y),a.z-b.z); }
double dot  (P3D p, P3D q)   { return p.x*q.x+p.y*q.y+p.z*q.z; }
double dist2(P3D p, P3D q)   { return dot(p-q,p-q); }
double cross(P3D p, P3D q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const P3D &p) {
  os << "(" << p.x << "," << p.y << "," << p.z << ")"; 
}

int main(){
	P3D p[MAX]; P3D t; int bean[10]={0}, n=0;
	while(cin >> p[n].x >> p[n].y >> p[n].z
					   && (p[n]!=P3D(P2D(0,0),0))) n++;
	double Min; int id;
	for(int i=0 ; i<n ; i++){
		Min = 11;
		for(int j=0 ; j<n ; j++){
			if(i==j) continue;
			Min = min(Min, sqrt(dist2(p[i],p[j])));
		}
		id = (int) Min; 
		if(id < 10) bean[id]++;
	}
	for(int i=0 ; i<10 ; i++){
		printf("%4d",bean[i]);
	}
	printf("\n");
}
