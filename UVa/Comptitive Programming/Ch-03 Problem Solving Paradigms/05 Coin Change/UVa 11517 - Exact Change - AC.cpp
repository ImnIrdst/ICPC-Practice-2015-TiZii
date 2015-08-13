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

int total, coins[110], dp[10010][110], n, MinPrice, MinCoin;

int MinAmount(int price, int i){
	if(price>=total) return price;
	if(i>=n) return INF;
	if(dp[price][i]!=-1) return dp[price][i];
	return dp[price][i]=min(MinAmount(price+coins[i],i+1),MinAmount(price,i+1));
}

int MinCoins(int price, int i){
	if(price==MinPrice) return 0;
	if(i>=n || price>MinPrice) return INF;
	if(dp[price][i]!=-1) return dp[price][i];
	return dp[price][i]=min(MinCoins(price+coins[i],i+1)+1,MinCoins(price,i+1));
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> total >> n;
		memset(dp,-1,sizeof dp);
		for(int i=0 ; i<n ; i++) cin >> coins[i];
		MinPrice=MinAmount(0,0); memset(dp,-1,sizeof dp); MinCoin=MinCoins(0,0);
		cout << MinPrice << " " << MinCoin << endl;
	}
	return 0;
}