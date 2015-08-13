#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

const int Inf = 1e9;
const int MaxK = 100+10;
const int MaxCash=(10+1)*100+10;
const int MaxPicks=2*(10+1)+10;

int dp[MaxCash][MaxPicks][MaxK][2]; int Price[MaxK], Des[MaxK], n, x, t, k, Maxmoney;

int solve(int Cash, int RemPicks, int K, int CanDoublePick){
	if(Cash < 0 || RemPicks < 0 || K>k) return -Inf;
	if(K==k) return 0;
	int& dpp = dp[Cash][RemPicks][K][CanDoublePick];
	if(dpp!=-1) return dpp; dpp = -Inf;
	if(CanDoublePick) dpp = max(dpp, solve(Cash-Price[K], RemPicks-1, K, 0)+Des[K]); 
	dpp = max(dpp, solve(Cash-Price[K], RemPicks-1, K+1, 1)+Des[K]);
	dpp = max(dpp, solve(Cash         , RemPicks  , K+1, 1));
	return dpp;
}

int main(){
	while(cin >> n >> x >> t >> k && (n||x||t||k)){
		memset(dp, -1, sizeof dp);

		int sum=0;
		for(int i=0 ; i<k ; i++){
			cin >> Price[i] >> sum;
			for(int j=0 ; j<n ; j++){
				int tmp; cin >> tmp; sum+=tmp;
			}
			Des[i]=sum;
		}
		Maxmoney = floor(double(x * (n + 1)) / 1.1 + 1e-6) - (n + 1) * t;

		printf("%.2lf\n", double(solve(Maxmoney, 2*(n+1), 0, 1))/(n+1));
	}
}