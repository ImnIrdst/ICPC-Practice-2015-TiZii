#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>

using namespace std;

const double INF = 1e100;
const double EPS = 1e-12;
const int MAX = 100;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator < (const PT &p)  const { if( fabs(x-p.x)>EPS ) return x<p.x; return y<p.y; }
  bool operator ==(const PT &p)  const { return x==p.x && y==p.y;}
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

PT cords[MAX];

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		int n; cin >> n; set<PT> st;
		for(int i=0 ; i<n ; i++){
			cin >> cords[i].x >> cords[i].y; st.insert(cords[i]);
		}
		set<PT>::iterator i,j,k; int MaxAns=2;
		for(i=st.begin() ; i!=st.end() ; i++){
			for(j=i ; j!=st.end() ; j++){
				if(i==j) continue;
				int ans=2;
				for(k=j ; k!=st.end() ; k++){
					if(k==i || k==j) continue;
					ans += LinesCollinear(*i,*j,*j,*k);
				}
				MaxAns=max(ans,MaxAns);
			}
		}
		if(st.size()==1) printf("Data set #%d contains a single gnu.\n",t++);
		else printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", t++, st.size(), MaxAns);
	}
}
