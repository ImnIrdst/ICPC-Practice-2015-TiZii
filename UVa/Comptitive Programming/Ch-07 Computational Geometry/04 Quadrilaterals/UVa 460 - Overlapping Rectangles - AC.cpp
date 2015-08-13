#include <iostream>
#include <algorithm>

using namespace std;


struct PT { double x, y; PT() {} PT(double x, double y) : x(x), y(y) {} };

int main(){
	PT p11,p12,p21,p22,i1,i2; int tc; cin >> tc;
	while(tc--){
		cin >> p11.x >> p11.y >> p12.x >> p12.y;
		cin >> p21.x >> p21.y >> p22.x >> p22.y;
		i1.x = max(p11.x , p21.x); i1.y = max(p11.y , p21.y);
		i2.x = min(p12.x , p22.x); i2.y = min(p12.y , p22.y);
		if(i1.x >= i2.x || i1.y>=i2.y) cout << "No Overlap" << endl;
		else cout << i1.x << " " << i1.y << " " << i2.x << " " << i2.y << endl;
		if(tc) cout << endl;
	}
}

// #include <iostream>
// #include <cmath>
// #include <cstdio>
// #define pi (2*acos(0))

// using namespace std;

// const double INF = 1e100;
// const double EPS = 1e-12;

// int dcmp(double x){
// 	if(fabs(x) < EPS) return 0; else return x < 0 ? -1 : 1;
// }


// struct PT { 
//   double x, y; 
//   PT() {}
//   PT(double x, double y) : x(x), y(y) {}
//   PT(const PT &p) : x(p.x), y(p.y)    {}
//   PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
//   PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
//   PT operator * (double c)     const { return PT(x*c,   y*c  ); }
//   PT operator / (double c)     const { return PT(x/c,   y/c  ); }
// bool operator < (const PT &p)  const { if(dcmp(p.x-x)!=0) return dcmp(p.y-y)==1; return dcmp(p.x-x)==1; }
// };

// typedef PT VEC;

// double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
// double dist2(PT p, PT q)   { return dot(p-q,p-q); }
// double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// double Length(VEC A) { return sqrt(dot(A, A)); }

// VEC Normal(VEC A){
// 	double L = Length(A); return VEC (-A.y/L, A.x/L);
// }

// PT GetLineIntersection(PT P, VEC v, PT Q, VEC w){
// 	VEC u = P-Q; 
// 	if(cross(v, w)==0) return PT(INF,INF);
// 	double t = cross(w, u) / cross(v, w);
// 	return P+v*t;
// }

// ostream &operator<<(ostream &os, const PT &p) {
//   os << "" << p.x << " " << p.y << ""; 
// }

// PT PR1[4], PR2[4]; // PR = Points of Rectangle

// bool isInRectangles(PT a){
// 	return ((a.x>=PR1[0].x && a.x<=PR1[1].x && a.y>=PR1[0].y && a.y<=PR1[1].y) 
// 		 && (a.x>=PR2[0].x && a.x<=PR2[1].x && a.y>=PR2[0].y && a.y<=PR2[1].y));
// }

// double Area(PT p1, PT p2){
// 	return fabs((p1.x-p2.x)*(p1.y-p2.y));
// }

// int main(){
// 	int tc,n=4; cin >> tc;
// 	while(tc--){
// 		cin >> PR1[0].x >> PR1[0].y >> PR1[1].x >> PR1[1].y;
// 		PR1[2] = PT(PR1[0].x,PR1[1].y); PR1[3] = PT(PR1[1].x,PR1[0].y);

// 		cin >> PR2[0].x >> PR2[0].y >> PR2[1].x >> PR2[1].y;
// 		PR2[2] = PT(PR2[0].x,PR2[1].y); PR2[3] = PT(PR2[1].x,PR2[0].y);


// 		PT ans1=PT(INF,INF), ans2=PT(-INF,-INF); // intersection Points
// 		for(int i=0 ; i<n ; i++){
// 			for(int j=i+1 ; j<n ; j++){
// 				if(!(PR1[i].x==PR1[j].x || PR1[i].y==PR1[j].y)) continue;
// 				for(int i2=0 ; i2<n ; i2++){
// 					for(int j2=i2+1 ; j2<n ; j2++){
// 						if(!(PR2[i2].x==PR2[j2].x || PR2[i2].y==PR2[j2].y)) continue;
// 						PT tmp = GetLineIntersection(PR1[i],  VEC(PR1[j]-PR1[i]),
// 													 PR2[i2], VEC(PR2[j2]-PR2[i2]));
// 						if(isInRectangles(tmp)){
// 							if(tmp < ans1) ans1=tmp;
// 							if(ans2 < tmp) ans2=tmp;
// 						}
// 						//cout << PR1[i] << PR1[j] << PR2[i2] << PR2[j2];
// 						//cout << tmp << isInRectangles(tmp)  << " " << endl;
// 					}
// 				}
// 			}
// 		}
// 		if(Area(ans1,ans2)<EPS || Area(ans1,ans2) > 1e100) cout << "No Overlap" << endl;
// 		else cout << ans1 << " " << ans2 << endl;
// 		if(tc) cout << endl;
// 	}
// }