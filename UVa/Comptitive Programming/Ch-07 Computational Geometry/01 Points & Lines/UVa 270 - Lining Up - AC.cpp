#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <set>

#define  EPS (1e-11)
#define  MAX (700+10)
#define  INF ((int)1e9)

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int gcd(int a,int b){if(b==0) return (!a?1:a); return gcd(b,a%b);}

struct Point{
	int x, y;
	Point(int x = 0, int y = 0) { 
		this->x=x/gcd(x,y); this->y=y/gcd(x,y);
		if(x<0) x=-x, y=-y;
	}
	bool operator < (const Point& a) const
	{
		if(a.x != x) return x < a.x;
		return y < a.y;
	}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }

Vector operator - (Point A, Point B) { return Vector(A.x-B.x, A.y-B.y); }

Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }

Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }

int dcmp(double x){
	if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point &b){
	return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

Point p[MAX], p2[MAX];

int main(){
	int tc; cin >> tc; cin.ignore(); cin.ignore(); string str;
	while(tc--){
		int n=0,x,y, ans=2, cnt;
		while(getline(cin,str) && str!=""){
			stringstream sstr(str);
			sstr >> p[n].x >> p[n].y; p[n]= n++;
		}
		sort(p,p+n);
		for(int o=0 ; o<n ; o++){
			for(int i=0, j=0 ; i<n ; i++){
				if(i==o) continue;
				p2[j++]=Point(p[o].x-p[i].x,p[o].y-p[i].y);
			}
			sort(p2,p2+n-1); cnt=2;
			for(int i=1 ; i<n-1 ; i++){
				//cout << p2[i].x << " " << p2[i].y << endl;
				if(p2[i].x!=p2[i-1].x || p2[i].y!=p2[i-1].y) cnt=2;
				else cnt++; ans = max(cnt,ans);
			}
			//cout << endl;
		}
		cout << ans << endl;
		if(tc) cout << endl;
	}
}
