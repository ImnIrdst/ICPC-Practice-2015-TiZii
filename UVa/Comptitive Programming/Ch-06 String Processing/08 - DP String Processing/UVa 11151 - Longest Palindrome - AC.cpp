#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX (1000+10)

using namespace std;

string str; int dp[MAX][MAX];

int solve(int L, int R){
	if(L==R) return 1;
	if(L+1==R && str[L]==str[R]) return 2;
	int& dpp=dp[L][R]; if(dpp!=-1) return dpp;
	if(str[L]==str[R]) return dpp=solve(L+1,R-1)+2;
	if(str[L]!=str[R]) return dpp=max(solve(L+1,R),solve(L,R-1));
}

int main(){
	int tc; cin >> tc; cin.ignore();
	while(tc--){
		getline(cin,str); memset(dp,-1,sizeof dp);
		if(str.length()) cout << solve(0,str.length()-1) << endl;
		else cout << 0 << endl;
	}
}