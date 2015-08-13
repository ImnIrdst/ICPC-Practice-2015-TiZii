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

int w[1000+10],p[1000+10],dp[30+10][1000+10],totw,n,m;

int knapsack(int weight, int i){
	if(weight>totw ) return -1*INF;
	if(i>=n) return 0;
	if(dp[weight][i]!=-1) return dp[weight][i];
	return dp[weight][i]=max(knapsack(weight,i+1),knapsack(weight+w[i],i+1)+p[i]);
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++) scanf("%d %d",&p[i],&w[i]);
		scanf("%d", &m); int sum=0;
		while(m--){
			scanf("%d", &totw);
			memset(dp,-1,sizeof dp);
			sum+=knapsack(0,0);
		}
		cout << sum << endl;
	}
	return 0;
}