#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long
#define maxn 1000
#define maxh 10

using namespace std;

int dp[15][1010], a[15][1010]={0}, N;

int solve(int n, int h){
	if(n==0 && h==9) return 0;
	//if((n!=0 && n!=N) && h==9) return INF;
	if(h>9 || h<0 || n<0) return INF;
	if(dp[h][n]!=-1) return dp[h][n];
	int ans=INF;
	if( n-1>=0 && h-1>0)  ans=min(ans,solve(n-1,h)-a[h][n-1]+30);
	if( n-1>=0 && h-1>=0) ans=min(ans,solve(n-1,h-1)-a[h-1][n-1]+20);
	if( n-1>=0 && h+1<10) ans=min(ans,solve(n-1,h+1)-a[h+1][n-1]+60);
	return dp[h][n]=ans;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		for(int i=0 ; i<maxh ; i++){
			for(int j=0 ; j<maxn ; j++){
				dp[i][j]=-1;
			}
		}
		int n; cin >> n; n/=100;
		for(int j=0 ; j<10 ; j++){
			for(int i=0 ; i<n ; i++){
				cin >> a[j][i];
			}
		}
		N=n;
		cout << solve(n,9) << endl << endl;
	}
	return 0;
}