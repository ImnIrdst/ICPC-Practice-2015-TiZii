#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9

using namespace std;

int a[20][20],n,dp[1<<20][20]; // a == grid

int ones(int bitset){int cnt=0; do{cnt+=bitset&1;}while(bitset>>=1); return cnt;}

int solve(int bitset, int j){
	if(bitset==(1<<n)-1) return 0;
	int& dpp=dp[bitset][j]; int i=ones(bitset);
	if(dpp!=-1) return dpp;
	dpp=INF;
	for(int k=0 ; k<n ; k++){
		if(!(bitset&(1<<k))){
			dpp=min(dpp,solve(bitset|(1<<k),k)+a[i][k]);
		}
	}
	return dpp;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j];
			}
		}
		memset(dp ,-1 , sizeof dp);
		cout << solve(0,0) << endl;
	}
	return 0;
}