#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

double R[10], C[10]; // R = Radius, C = Center

double Dist(int i, int j){
	return sqrt(4*R[i]*R[j]);//(ri+rj)^2 - (ri-rj)^2
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		for(int i=0 ; i<n ; i++){
			cin >> R[i];
		}
		double ans=(double)1e9;
		sort(R,R+n);
		do{
			for(int i=0 ; i<n ; i++){
				C[i]=R[i];
				for(int j=0 ; j<i ; j++){
					C[i]=max(C[i],C[j]+Dist(i,j));
				}
				//cout << C[i] << endl;
			}
			double Max=-1;
			for(int i=0 ; i<n ; i++){
				Max=max(Max, R[i]+C[i]);
			}
			ans = min( ans, Max );
		}while(next_permutation(R,R+n));
		printf("%.3lf\n", ans);
	}
}