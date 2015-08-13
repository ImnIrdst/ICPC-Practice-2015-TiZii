#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

#define	M_PI	acos(-1)

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
};

double dist(PT a, PT b){
	return hypot(a.x-b.x, a.y-b.y);
}

bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || 
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

int main(){
	char c; PT pt, pt2; int ii=0;
	vector<vector<PT> > poly(12); vector<char> types;
	while(cin >> c && c!='*'){
		types.push_back(c);
		int n=0;
		if(c=='r'){
			cin >> pt.x >> pt.y >> pt2.x >> pt2.y;
			poly[ii].push_back(pt); poly[ii].push_back(PT(pt2.x,pt.y));
			poly[ii].push_back(pt2); poly[ii].push_back(PT(pt.x,pt2.y));
		}
		if(c=='t'){
			for(int i=0 ; i<3 ; i++){
				cin >> pt.x >> pt.y; poly[ii].push_back(pt);
			}
		}
		if(c=='c'){
			PT r; cin >> pt.x >> pt.y >> r.x;
			poly[ii].push_back(pt); poly[ii].push_back(r);
		}
		ii++;
	}
	int cs=1;
	while(cin >> pt.x >> pt.y && (pt.x!=9999.9 || pt.y!=9999.9)){
		bool contained=false;
		for(int i=0 ; i<poly.size() ; i++){
			if(!poly[i].size()) continue;
			if(types[i] == 'c'){
				if(dist(pt,poly[i][0])<poly[i][1].x){
					cout << "Point " << cs << " is contained in figure " << i+1 << endl; contained=true;
				}
			}else{
				if(PointInPolygon(poly[i],pt)){
					cout << "Point " << cs << " is contained in figure " << i+1 << endl; contained=true;
				}
			}
		}
		if(!contained) cout << "Point " << cs << " is not contained in any figure" << endl;
		cs++;
	}
}