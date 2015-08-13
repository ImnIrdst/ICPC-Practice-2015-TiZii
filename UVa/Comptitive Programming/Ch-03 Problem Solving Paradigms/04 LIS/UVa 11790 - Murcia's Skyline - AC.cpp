#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define MAX 100000

using namespace std;

int h[MAX], w[MAX], dp[MAX];

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		int n; cin >> n;
		memset(dp,0,sizeof dp);
		for(int i=0 ; i<n ; i++) cin >> h[i];
		for(int i=0 ; i<n ; i++) cin >> w[i];
		int ans1=0, ans2=0;
		for(int i=0 ; i<n ; i++){
			dp[i]=w[i];
			for(int j=0 ; j<i ; j++){
				if(h[i]>h[j] && dp[j]+w[i]>dp[i]) dp[i]=dp[j]+w[i];
			}
			if(dp[i]>ans1) ans1=dp[i];
		}

		for(int i=0 ; i<n ; i++){
			dp[i]=w[i];
			for(int j=0 ; j<i ; j++){
				if(h[i]<h[j] && dp[j]+w[i]>dp[i]) dp[i]=dp[j]+w[i];
			}
			if(dp[i]>ans2) ans2=dp[i];
		}
		if(ans1>=ans2) printf("Case %d. Increasing (%d). Decreasing (%d).\n", t++ , ans1, ans2);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n", t++ , ans2, ans1);
	}
	return 0;
}