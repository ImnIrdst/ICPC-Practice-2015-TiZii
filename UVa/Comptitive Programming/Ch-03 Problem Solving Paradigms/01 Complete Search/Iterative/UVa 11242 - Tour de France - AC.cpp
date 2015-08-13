#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9

using namespace std;

double f[10+10],s[10+10],ratio[100+10];

int main(){
	int n, m;
	while(cin >> n && n{
		cin >> m;
		for(int i=0 ; i<n ; i++) cin >> f[i];
		for(int i=0 ; i<m ; i++) cin >> r[i];
		for(int i=0, top=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				ratio[top++]=r[i]/f[j];
			}
		}
		sort(ratio,ratio+m*n); double Max=-1;
		for(int i=0 ; i<m*n-1 ; i++){
			Max=max(Max,ratio[i+1]/ratio[i])
		}
		printf("%.2lf\n",Max);
	}
	return 0;
}