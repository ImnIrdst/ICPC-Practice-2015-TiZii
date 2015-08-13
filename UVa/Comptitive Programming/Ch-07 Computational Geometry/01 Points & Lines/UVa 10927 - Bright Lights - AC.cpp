#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const double EPS = 1e-9;

struct pt{ double x, y;
	pt(double x=0, double y=0): x(x), y(y){}
	pt operator - (const pt &p)  const { return pt(x-p.x, y-p.y); }
	bool operator < (const pt &p) const;//  const { return pt(x-p.x, y-p.y); }
};

double dist(pt a, pt b){
	return hypot(a.x-b.x, a.y-b.y);
}

typedef pt vec;
typedef pair<pt, int> ppti;

int dcmp(double a, double b){
	if(fabs(a-b)<EPS) return 0;
	else return (a<b ? -1 : +1);
}

double Cross(vec A, vec B) { 
	return A.x*B.y - A.y*B.x; 
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double angle(pt a, pt o, pt b) { // returns angle aob in rad
	vec oa = a-o, ob = b-o;
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool pt::operator<(const pt& b) const {
	pt a = *this;
	double ang1 = angle(a, pt(0,0) , pt(1, 0));
	double ang2 = angle(b, pt(0,0), pt(1, 0));
	if (fabs(ang1 - ang2) > EPS)
		return ang1 < ang2;
	return dist(a, pt(0,0)) < dist(b, pt(0,0)); 
}

bool cmp(const pt& a, const pt& b){
	return (a.x==b.x ? a.y<b.y : a.x < b.x);
}

int main(){
	int n, cs=1;
	while(cin >> n  && n){
		vector<ppti> pole(n);
		for(int i=0 ; i<n ; i++){
			cin >> pole[i].first.x >> pole[i].first.y >> pole[i].second;
		}

		sort(pole.begin(), pole.end());
		vector<pt> ans;
		double PrevH=pole[0].second;
		pt prevPole=pole[0].first;
		for(int i=1 ; i<n ; i++){
			pt curPole = pole[i].first;
			double curH = pole[i].second;
			if(dcmp(Cross(curPole, prevPole),0)==0){
				if(dcmp(curH,PrevH)<=0) 
					ans.push_back(pole[i].first);
				PrevH=max(PrevH, curH);
			}
			else prevPole=curPole, PrevH=curH;
		}

		sort(ans.begin(), ans.end(), cmp);

		cout << "Data set " << cs++ << ":" << endl;
		if(ans.size()==0) cout << "All the lights are visible." << endl;
		else              cout << "Some lights are not visible:" << endl;
		for(int i=0 ; i<ans.size() ; i++){
			cout << "x = " << ans[i].x << ", y = " << ans[i].y;
			if(i!=ans.size()-1) cout << ";"; else cout << "."; cout << endl;
		}
	}
}