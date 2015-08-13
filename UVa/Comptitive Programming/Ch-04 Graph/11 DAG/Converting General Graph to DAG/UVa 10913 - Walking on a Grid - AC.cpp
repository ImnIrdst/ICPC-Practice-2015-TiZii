#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX (75+10)

using namespace std;

int a[MAX][MAX],n,hasAns,dp[MAX][MAX][5+10][3]; vector<int> stk; enum dir{L,R,D};

int inRange(int i, int j){ return (i>=0 && j>=0 && i<n && j<n); }

int solve(int i, int j, int k, dir pd){//pd == parent dir
	if(!inRange(i,j)) return -INF;
	int& dpp=dp[i][j][k][pd];
	if(a[i][j]<0) k--; 
	if(k<0) return -1*INF;
	if(i==n-1 && j==n-1){ hasAns=true; return a[i][j]; }
	if(dpp!=-1) return dpp;
	if(pd==L) dpp=max(solve(i+1,j,k,D),solve(i,j+1,k,L));
	if(pd==R) dpp=max(solve(i+1,j,k,D),solve(i,j-1,k,R));
	if(pd==D) dpp=max(solve(i+1,j,k,D),max(solve(i,j-1,k,R),solve(i,j+1,k,L)));
	dpp+=a[i][j];
	return dpp;
}

int main(){
	int k,t=1;
	while(cin >> n >> k && (n||k)){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j];
			}
		}
		memset(dp,-1,sizeof dp); hasAns=false; int ans=solve(0,0,k,D);
		if( hasAns) printf("Case %d: %d\n", t++, ans );
		if(!hasAns) printf("Case %d: %s\n", t++,  "impossible" );
	}
	return 0;
}