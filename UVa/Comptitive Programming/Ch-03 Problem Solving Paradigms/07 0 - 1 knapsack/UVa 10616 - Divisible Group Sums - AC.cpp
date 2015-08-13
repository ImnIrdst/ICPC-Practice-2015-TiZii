#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

int64 n,q,m,d,pq,dp[20+10][10+10][200+10], a[200+10];

int posMod(int64 a, int d){return (a%d>=0 ? a%d : a%d+d);} // positive mod

int64 solve(int sum, int cnt, int i){
	if(i>n) return 0;
	if(cnt==m && sum==0) return 1;
	if(cnt==m && sum!=0) return 0;
	int64& dpp=dp[sum][cnt][i];
	if(dpp!=-1) return dpp;
	dpp=solve(posMod(sum+a[i],d),cnt+1,i+1)+solve(sum,cnt,i+1);
	return dpp;
}

int main(){
	int t=1;
	while(cin >> n >> q && (n || q)){
		for(int i=0 ; i<n ; i++) cin >> a[i];
		printf("SET %d:\n", t++);
		for(int i=0 ; i<q ; i++){
			cin >> d >> m;
			memset(dp,-1,sizeof dp);
			printf("QUERY %d: %lld\n", i+1, solve(0,0,0));
		}
	}
	return 0;
}