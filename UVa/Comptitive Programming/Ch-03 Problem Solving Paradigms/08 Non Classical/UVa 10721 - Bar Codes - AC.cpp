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

int64 N, K, M, dp[60][60][60];

int64 solve(int n,int k , int m, int flag, string s){// flag and s used only for debugging
	s+='0'+flag;//for debug
	if(m>M || k>K || n>=N)  return 0;
	if(n==N-1 && k==K)  return 1;
	if(dp[n][k][m]!=-1) return dp[n][k][m];
	return dp[n][k][m]=solve(n+1,k+1,1,1-flag,s)+solve(n+1,k,m+1,flag,s);
}

int main(){
	while(cin >> N >> K >> M){
		for(int i=0 ; i<60 ; i++)
			for(int j=0 ; j<60 ; j++)
				for(int k=0 ; k<60 ; k++)
					dp[i][j][k]=-1;
		cout << solve(0,1,1,1,"") << endl;
	}
	return 0;
}