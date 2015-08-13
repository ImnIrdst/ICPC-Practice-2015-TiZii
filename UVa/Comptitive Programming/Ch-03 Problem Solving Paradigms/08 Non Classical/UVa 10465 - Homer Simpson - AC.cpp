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

int t, dp[100010], m,n,m1,n1;

int main(){
	while(cin >> m1 >> n1 >> t){
		memset(dp, -1, sizeof dp); dp[0]=0;  m=min(m1,n1); n=max(m1,n1);
		for(int i=1 ; i<=t ; i++){
			if(i-n>=0 && dp[i-n]!=-1) dp[i]=dp[i-n]+1;
			if(i-m>=0 && dp[i-m]!=-1) dp[i]=dp[i-m]+1;
		}
		if(dp[t]!=-1) cout << dp[t] << endl;
		else for(int i=t ; i>=0 ; i--) 
				if(dp[i]!=-1){cout << dp[i] << " " << t-i << endl; break; }
	}
	return 0;
}