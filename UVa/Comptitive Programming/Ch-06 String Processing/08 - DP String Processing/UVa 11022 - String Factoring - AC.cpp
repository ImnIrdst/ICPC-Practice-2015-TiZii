#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[80+10][80+10]; char s[80+10];

int solve(int l, int r){
	int& dpp=dp[l][r];
	if(l==r) return 1;
	if(dp[l][r]) return dp[l][r];
	dpp = 1e9;
	for(int i=l ; i<r ; i++){
		dpp = min(dpp, solve(l,i)+solve(i+1,r));
	}
	int len = r-l+1;
	for(int i=1 ; i<=len ; i++){
		if(len%i==0){
			int k, j;
			for(k=l , j=0 ; k<=r ; k++){
				if(s[k] != s[j+l]) break; 
				j++; j%=i;
			}
			if(k == r+1 && r != l+i-1)
				dpp = min(dpp, solve(l,l+i-1));
		}
	}
	return dpp;
}

int main(){
	while(cin >> s && strcmp(s,"*")){
		memset(dp, 0, sizeof dp);
		cout << solve(0, strlen(s)-1) << endl;
	}
}