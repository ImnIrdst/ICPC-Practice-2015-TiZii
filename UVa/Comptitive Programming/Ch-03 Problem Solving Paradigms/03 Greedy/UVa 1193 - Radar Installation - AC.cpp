#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1e3 + 10;

struct Interval{
	double s, e; Interval(){}
	Interval(double s, double e) :s(s), e(e) {}
	bool operator<(const Interval& op) const {
		return (e != op.e ? e < op.e : s < op.s);
	}
};
vector<Interval> inters;

struct Pt{
	double x, y; Pt(){}
	Pt(double x, double y):x(x), y(y) {}
}pts[MAX];

int n, cs = 1; double d;

void add_new_interval(Pt p){ //solve the equ(p.y^2 + (X-p.x)^2 = d^2)
	double tmp = sqrt(d*d - p.y*p.y);
	inters.push_back(Interval(p.x - tmp, p.x + tmp));
}

int main(){
	while (cin >> n >> d && (n || d)){
		inters.clear();
		for (int i = 0; i < n; i++){
			cin >> pts[i].x >> pts[i].y;
			add_new_interval(pts[i]);
		}

		bool hasAns = true;
		for (int i = 0; i < n; i++){
			if (pts[i].y > d) hasAns = false;
		}
		if (!hasAns){
			cout << "Case " << cs++ << ": " << -1 << endl; continue;
		}
		sort(inters.begin(), inters.end());
		
		int ans = 0, j; 
		for(int i=0 ; i<n ;){
			Interval cur = inters[i];
			for (j = i + 1; j < n; j++){
				Interval nex = inters[j];
				if (cur.e < nex.s) break;
			}
			i = j;  ans++;
		}
		cout << "Case " << cs++ << ": " << ans << endl;
	}
}