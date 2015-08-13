#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <sstream>
#include <queue>
#define INF (int)1e9
#define MAXF (120+10)
#define MAXH (15+10)

using namespace std;

int dp[MAXF][MAXH], a[MAXF][MAXH][MAXH],n,m;

int solve(int f, int h){// f==floor, h==hole
	int& dpp=dp[f][h];
	if(f==0) return 0;
	if(dpp!=-1) return dpp;
	dpp=INF;
	for(int i=0 ; i<m ; i++){
		dpp=min(dpp,solve(f-1,i)+a[f-1][i][h]+2);
	}
	return dpp;
}

int main(){
	string str;
	while(cin >> str){
		cin >> n >> m; 
		for(int k=0 ; k<n-1 ; k++){
			for(int i=0 ; i<m ; i++){
				for(int j=0 ; j<m ; j++){
					cin >> a[k][i][j];
				}
			}
		}
		int ans=INF; memset(dp,-1,sizeof dp);
		for(int i=0 ; i<m ; i++){
			ans=min(ans,solve(n-1,i));
		}
		cout << str << endl;
		cout << ans << endl;
	}
	return 0;
}