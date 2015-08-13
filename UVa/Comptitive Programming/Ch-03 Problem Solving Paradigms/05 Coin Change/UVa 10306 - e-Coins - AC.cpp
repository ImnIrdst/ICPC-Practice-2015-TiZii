#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define p pair<int,int>
#define MAXW 300*300+10
#define MAXCOINS 100+10

using namespace std;

int coins[MAXCOINS][2], totw,n,m, dp[310][310], X, Y;

int emod(int a, int b){return a*a+b*b;}

int solve(int x, int y){
	if(x>X || y>Y) return INF;
	if(X==x && y==Y) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	int Min=INF;
	for(int i=0 ; i<n ; i++){
		Min=min(Min,solve(x+coins[i][0],y+coins[i][1])+1);
	}
	return dp[x][y]=Min;
}

int main(){
	int tc; cin >> tc; int sqtotw;
	while(tc--){
		scanf("%d", &n); scanf("%d", &totw); sqtotw=totw; totw*=totw;
		for(int i=0 ; i<n ; i++) scanf("%d %d",&coins[i][0],&coins[i][1]);
		int y;
		vector< p > v;
		for(int i=0 ; i<=sqtotw ; i++){
			for(int j=0 ; j<=sqtotw ; j++){
				if(i*i+j*j==totw){
					v.push_back(p(i,j));
				}
			}
		}
		int Min=INF;
		for(int i=0 ; i<v.size() ; i++){
			X=v[i].first, Y=v[i].second;
			memset(dp,-1,sizeof dp);
			Min=min(Min,solve(0,0));
		}
		
		if(Min!=INF) cout << Min << endl;
		else cout << "not possible" << endl;
	}
	return 0;
}