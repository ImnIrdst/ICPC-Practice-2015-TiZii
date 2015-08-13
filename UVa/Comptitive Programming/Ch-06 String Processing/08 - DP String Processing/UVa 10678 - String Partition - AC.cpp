#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long int64;

int64 dp[200+10], n; char s[200+10];

int64 solve(int ii){
	if(ii==n) return 0;
	int64& dpp=dp[ii];
	if(dpp!=-1) return dpp;
	if(s[ii]=='0') return dpp = solve(ii+1);
	int64 num=0; dpp=-1;
	for(int i=ii ; i<n ; i++){
		num=num*10+(s[i]-'0');
		if(num > INT_MAX) break;
		dpp = max(dpp, num+solve(i+1));
	}
	return dpp;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> s;    memset(dp, -1, sizeof dp); 
		n=strlen(s); cout << solve(0) << endl;
	}
}