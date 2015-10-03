#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int cf[10 + 5], n;

double NPV(double IRR){
	double sum = 0, denom = 1;
	for (int i = 0; i < n; i++){
		sum   += cf[i] / denom;
		denom *= (1 + IRR);
	}
	return sum;
}

int main(){
	while (cin >> n && n){ 
		n++;
		for (int i = 0; i < n; i++){
			cin >> cf[i];
		}

		double lo = -0.999, hi = 1e9;
		while (fabs(hi - lo) > 1e-4){
			double mid = (lo + hi) / 2;
			double npv = NPV(mid);
			if (npv > 0) lo = mid; else hi = mid;
		}

		if (fabs(hi + 1) < 1e-4){
			printf("No\n");
		}
		else printf("%.2lf\n", hi);
	}
}