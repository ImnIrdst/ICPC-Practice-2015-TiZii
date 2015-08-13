#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int gcd(int a, int b){
	return (b ? gcd(b,a%b) : a);
}

int main(){
	int n; vector<int> v;
	while(cin >> n && n){
		v.assign(n,0);
		for(int i=0 ; i<n ; i++){
			cin >> v[i];
		}
		int a=0, b=(n*(n-1))/2;
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				if(gcd(v[i],v[j])==1) a++;
			}
		}
		if(a==0)  printf("No estimate for this data set.\n");
		else	  printf("%.6lf\n", sqrt((b*6.0)/a));
	}
}