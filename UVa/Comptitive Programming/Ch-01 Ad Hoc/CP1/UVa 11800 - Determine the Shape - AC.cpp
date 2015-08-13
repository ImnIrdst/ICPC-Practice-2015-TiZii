#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct  pt{ int x, y; } pts[4];	
typedef pt vec;

vec Vec(pt a, pt b){ 
	vec v; v.x = b.x-a.x; v.y=b.y-a.y; return v; 
}

int coordcmp(pt& a, pt& b){
	if (a.x != b.x) return a.x < b.x; return a.y < b.y;
}

int anglecmp(pt& a, pt& b){
	vec n = Vec(pts[0], a);
	vec m = Vec(pts[0], b);
	return atan2(n.y, n.x) < atan2(m.y, m.x);
}


int dot(vec a, vec b){   return a.x*b.x + a.y*b.y; }
int cross(vec a, vec b){ return a.x*b.y - a.y*b.x; }
int parll(vec a, vec b){ return cross(a,b)==0; }

double dist(pt a, pt b){ return sqrt(hypot(b.x-a.x,b.y-a.y)); }

int main(){
	int tc, cs=1; cin >> tc;
	while(tc--){
		for(int i=0 ; i<4 ; i++) cin >> pts[i].x >> pts[i].y;
		sort(pts, pts+4, coordcmp); sort(pts+1, pts+4, anglecmp);

		double side[4];
		for(int i=0 ; i<4 ; i++)
			side[i] = dist(pts[i],pts[(i+1)%4]);//, cout << pts[i].x << "," << pts[i].y << " ";
		//cout << endl;
		int isRight = dot(Vec(pts[0],pts[3]), Vec(pts[0],pts[1]))==0;

		cout << "Case " << cs++ << ": ";// << endl;
		if(side[0]==side[1] && side[1]==side[2] && side[2]==side[3]){
			if(isRight) cout << "Square" << endl;
			else		cout << "Rhombus" << endl;
		}
		else if(side[0]==side[2] && side[1]==side[3]){
			if(isRight) cout << "Rectangle" << endl;
			else		cout << "Parallelogram" << endl;
		}
		else if(parll(Vec(pts[0], pts[1]), Vec(pts[3], pts[2]))
			 || parll(Vec(pts[0], pts[3]), Vec(pts[1], pts[2]))){
			cout << "Trapezium" << endl;
		}else cout << "Ordinary Quadrilateral" << endl;
	}
}