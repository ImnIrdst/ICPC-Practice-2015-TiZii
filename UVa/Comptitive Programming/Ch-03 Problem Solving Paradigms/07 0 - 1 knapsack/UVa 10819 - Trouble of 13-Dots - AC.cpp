#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e8

using namespace std;

int m, n, fav[100+10], prc[100+10], dp[10000+200+10][100+10];

int solve(int p, int i){ // p == price, i = index, rf == refund flag
	bool rf=(p>2000);
	if(i>n) return -1*INF;
	if(p>m+(rf?200:0) || i==n) return 0;
	int& dpp=dp[p][i];
	if(dpp!=-1) return dpp;
	rf=(p+prc[i]>2000); bool check=(p+prc[i]<=m+(rf?200:0));
	dpp=max(solve(p,i+1),solve(p+prc[i],i+1)+(check?fav[i]:0));
	return dpp;

}

int main(){
	while(cin >> m >> n){
		for(int i=0 ; i<n ; i++) cin >> prc[i] >> fav[i];
		memset(dp,-1,sizeof dp);
		cout << solve(0,0) << endl;
	}
	return 0;
}