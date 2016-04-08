#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <set>
#include <cstdio>

using namespace std;

const double PI = 2*acos(0);
const double R  = 1e3;
const int MAX   = 1e3 + 10;

int n, w;
vector<int> shrines, sacreds; 

void initShrines(){
	set<int> tmp;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < sacreds.size(); j++){
			if (i%sacreds[j] == 0){
				tmp.insert(i); break;
			}
		}
	}
	shrines.clear();
	set<int>::iterator itr;
	for (itr = tmp.begin(); itr != tmp.end(); itr++) shrines.push_back(*itr);
}

// ang in radians
double computeShrinesDist(double a, double b){
	double ang = (2 * PI * fabs(b - a)) / n;
	return 2 * R * sin(ang / 2);
}

bool canRepair(double maxLen){
	for (int s = 0, j = 0; s < shrines.size(); s++){
		int workers = 1; double curLen = 2 * R; j = 0;
		for (int i = s; j < shrines.size(); j++, i++){
			i = i % shrines.size();
			if (workers > w) break;
			double shdist = computeShrinesDist(shrines[i], shrines[(i + 1) % shrines.size()]);
			if (shdist + curLen > maxLen) workers++, curLen = 2*R; else curLen += shdist;
		}
		if (workers <= w)  return true;
		if (workers == w + 1 && j == shrines.size()) return true;
	}
	return false;
}

int main(){
	while (cin >> w && w){
		sacreds.clear();
		int d; cin >> n >> d;
		for (int i = 0, t; i < d; i++){
			cin >> t; sacreds.push_back(t);
		}
		initShrines();

		// binary search the answer
		double lo = 2*R, hi = 2 * PI*R + 2*R;
		while (fabs(lo - hi) > 1e-4){
			double mid = (lo + hi) / 2;
			if (canRepair(mid)) hi = mid; else lo = mid;
		}

		printf("%.1lf\n", hi);
	}
}