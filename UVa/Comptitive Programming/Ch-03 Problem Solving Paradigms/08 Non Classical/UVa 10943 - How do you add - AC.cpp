#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long

using namespace std;

int dp[110][110];

int solve(int n, int k){
	if(k==1) return 1;
	if(dp[n][k]!=-1) return dp[n][k];
	int ans=0;
	for(int i=0 ; i<=n ; i++){
		ans+=solve(n-i,k-1); ans%=1000000;
	}
	return dp[n][k]=ans;
}

int main(){
	int n,k;
	while(cin >> n >> k){
		if(!n && !k) return 0;
		for(int i=0 ; i<110 ; i++){
			for(int j=0 ; j<110 ; j++){
				dp[i][j]=-1;
			}
		}
		cout << solve(n,k) << endl;
	}
	return 0;
}