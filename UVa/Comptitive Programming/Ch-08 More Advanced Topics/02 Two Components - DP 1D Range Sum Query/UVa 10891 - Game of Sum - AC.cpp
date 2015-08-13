#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX (100+10)
#define inf ((int)1e9)

using namespace std;

int a[MAX], sum[MAX], dp;

int Sum(int i, int j){
	return sum[j]-sum[i]+a[i];
}

int Solve(int i, int j){
	if(i==j) return a[i];
	if(i==j+1) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int& ret=d[i][j]; ret = -inf;
	for(int k=i ; k<=j+1 ; k++) ret = max(ret,Sum(i,j)-Solve(k,j));
	for(int k=j ; k>=i-1 ; k--) ret = max(ret,Sum(i,j)-Solve(i,k));
	return (ret==-inf ? +inf : ret);
}

int main(){
	int n; 
	while(cin >> n && n){
		for(int i=0, s=0 ; i<n ; i++){
			cin >> a[i]; Sum[i]=a[i]+s; s=Sum[i];
		}// TODO use abs
		memset(dp,-1,sizeof dp);
		cout << Sum(0,n-1)-2*Solve(0,n-1) << endl;
	}
}

