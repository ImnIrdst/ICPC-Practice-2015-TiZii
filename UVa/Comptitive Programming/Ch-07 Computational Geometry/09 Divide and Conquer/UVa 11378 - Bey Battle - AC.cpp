#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct pt{
	int x, y; pt(int x=0, int y=0): x(x), y(y){}
	bool operator<(const pt& a) const { return (x!=a.x? x<a.x : y<a.y); }
};

const int MAX = 100000+10; pt p[MAX];

void ClosestPair(int lo, int hi, int& ret){
	if(lo>=hi) return;
	int m = (lo+hi)/2;
	ClosestPair(lo, m, ret); ClosestPair(m+1, hi, ret);

	for(int i=m ; i>=lo ; i--){
		if(p[m].x-p[i].x >= ret) break;
		for(int j=m+1 ; j<=hi ; j++){
			if(p[j].x-p[i].x >= ret) break;
			ret = min(ret, max(p[j].x-p[i].x, abs(p[j].y-p[i].y)));
		}
	}
}

int main(){
	int n;
	while(cin >> n){
		for(int i=0 ; i<n ; i++){
			cin >> p[i].x >> p[i].y;
		}
		sort(p, p+n);
		int ans = 1e9; ClosestPair(0,n-1,ans);
		cout << ans << endl;
	}
}