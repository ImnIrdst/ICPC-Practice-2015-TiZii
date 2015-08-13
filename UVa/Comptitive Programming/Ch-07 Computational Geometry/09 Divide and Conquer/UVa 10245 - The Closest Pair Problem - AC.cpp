#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define  dist(i,j) ((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))
#define  MAX 10000

using namespace std;

int main(){
	double MinDist, Dist, x[MAX], y[MAX]; int n;
	while(cin >> n && n){
		MinDist = (int)1e9;
		for(int i=0 ; i<n ; i++){
			cin >> x[i] >> y[i];
		}
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				MinDist = min(MinDist, dist(i,j));
			}
		}
		MinDist = sqrt(MinDist);
		if(MinDist < 10000) printf("%.4lf\n", MinDist);
		else printf("INFINITY\n");
	}
}
