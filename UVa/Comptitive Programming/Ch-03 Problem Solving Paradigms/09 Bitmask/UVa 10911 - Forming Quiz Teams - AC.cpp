#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define eps (double)1e-9
#define INF (int)1e9
#define P pair<int,int>
#define X first
#define Y second

using namespace std;

int n; double dp[1<<17]; P a[17];

double dist(P a, P b){ return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y)); }

double solve(int bitmask){
	if(bitmask==(1<<n)-1) return 0;
	if(dp[bitmask]+1>eps) return dp[bitmask];
	dp[bitmask]=INF; int i=0;
	for(i=0 ; i<n ; i++){
		if(!(bitmask&(1<<i))) break;
	}
	for(int j=i+1 ; j<n ; j++){
		if(!(bitmask&(1<<j))){
			double slv=solve(bitmask|(1<<i)|(1<<j))+dist(a[i],a[j]);
			dp[bitmask]=min(dp[bitmask],slv);
		}
	}
	
	return dp[bitmask];
}

int main(){
	int t=1; char str[30];
	while(cin >> n && n){
		n*=2;
		for(int i=0 ; i<n ; i++) cin >> str >> a[i].X >> a[i].Y;
		memset(dp,-1,sizeof dp);
		printf("Case %d: %.2lf\n",t++, solve(0));
	}
	return 0;
}