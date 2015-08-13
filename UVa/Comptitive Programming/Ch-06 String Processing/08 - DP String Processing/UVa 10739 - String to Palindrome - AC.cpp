#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX (1000+10)

using namespace std;

string str; int dp[MAX][MAX], n;


int solve(int i, int j){
	//if(i<0 || j>n || i>j+1) return 1e9;
	if(i==j) return 0;
	if(i+1==j) return str[i]!=str[j];  
	
	int& dpp = dp[i][j];
	if(dpp!=-1) return dpp; dpp = 1e9;
	
	if(str[i]==str[j]) dpp = min(dpp,solve(i+1,j-1));
	else{
		dpp = min(dpp, solve(i+1,j-1)+1);
		dpp = min(dpp, solve(i+1,j)+1);
		dpp = min(dpp, solve(i,j-1)+1);
	}
	return dpp;
}

int main(){
	int cs=1, tc; cin >> tc;
	while(tc--){	
		cin >> str; n = str.length();
		memset(dp,-1,sizeof dp);
		cout << "Case " << cs++ << ": " << solve(0,n-1) << endl;
	}
}