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

int a[250+5],n,sum[250+5], dp[250+5][250+5];

int SUM(int i, int j){ return (j<i ? 0 : sum[j]-sum[i-1]); }

int solve(int L, int R){
	if(L==R || R<L) return 0;
	if(dp[L][R]!=-1) return dp[L][R];
	dp[L][R]=INF;
	for(int i=L ; i<=R ; i++){
		dp[L][R]=min(dp[L][R],solve(L,i-1)+solve(i+1,R)+SUM(L,R)-a[i-1]);
	}
	return dp[L][R];
}

int main(){
	while(cin >> n){
		memset(dp,-1,sizeof dp); memset(sum,0,sizeof sum);
		for(int i=0 ; i<n ; i++){ cin >> a[i]; sum[i+1]+=sum[i]+a[i]; }
		cout << solve(1,n) << endl;
	}	
	return 0;
}