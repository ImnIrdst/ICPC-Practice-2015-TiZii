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

int n,a[10+5],p[10+5][10+5],dp[10+5][10+5];

int solve(int L, int R){
	if(L==R){ return 0; }
	if(dp[L][R]!=-1) return dp[L][R];
	int Min=INF;
	for(int i=L ; i<R ; i++){
		int slv=solve(L,i)+solve(i+1,R)+a[(L-1)]*a[i]*a[R];
		if(Min>slv){
			Min=slv;
			p[L][R]=i;
		}
	}
	return dp[L][R]=Min;
}

void print(int L, int R){
	if(L==R){ cout << "A" <<L; return; }
	cout << "(";
	print(L,p[L][R]);
	cout << " x ";
	print(p[L][R]+1,R);
	cout << ")";
}

int main(){
	int t=1;
	while(cin >> n && n){
		for(int i=1 ; i<=n ; i++){
			cin >> a[i-1] >> a[i];
		}
		memset(dp,-1,sizeof dp);
		solve(1,n);//cout << solve(1,n) << endl;
		printf("Case %d: ",t++); print(1,n); printf("\n");
	}
	return 0;
}