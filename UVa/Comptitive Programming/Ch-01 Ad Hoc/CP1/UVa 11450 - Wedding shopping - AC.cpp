#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define inf (int)1e9

using namespace std;

int a[20+10][20+10]={0}, dp[200+10][20+10][20+10],m,n,sum;

int solve(int w, int g, int i){
	if(g==n && w<=m) return 0;
	if(i>a[g][0] || w>m) return -1*inf;
	int& dpp=dp[w][g][i];
	if(dpp!=-1) return dpp;
	return dpp=max(solve(w,g,i+1),solve(w+a[g][i],g+1,1)+a[g][i]);
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> m >> n; sum=0;
		for(int i=0 ; i<n ; i++){
			cin >> a[i][0];
			for(int j=1 ; j<=a[i][0] ; j++){
				cin >> a[i][j];
			}
			sort(a[i]+1, a[i]+1+a[i][0]);
			sum+=a[i][1];
		}
		memset(dp,-1,sizeof dp);
		if(sum>m) cout << "no solution" << endl;
		else cout << solve(0,0,1) << endl;
	}
	return 0;
}