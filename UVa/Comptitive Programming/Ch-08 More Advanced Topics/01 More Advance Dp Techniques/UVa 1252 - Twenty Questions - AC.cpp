#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int obj[128+10], dp[1<<11][1<<11], n, m;

int solve(int qbit, int abit){ // question bitmask, answer bitmask
	int& dpp = dp[qbit][abit];
	if( dpp != -1) return dpp;
	
	int cnt=0;
	for(int i=0 ; i<n ; i++){
		if( (obj[i]&qbit) == (abit) ) cnt++;
	}
	if(cnt <= 1) return dpp = 0;

	dpp = 1e9;
	for(int i=0 ; i<m ; i++){
		if(!(qbit&(1<<i))){
			dpp = min(dpp, 
				1+max(solve(qbit|(1<<i), abit),solve(qbit|(1<<i), abit|(1<<i))));
			i=i;
		}
	}
	return dpp;
}

int main(){
	while(cin >> m >> n && (n||m)){
		char c;
		for(int i=0 ; i<n ; i++){ 
			obj[i]=0;
			for(int j=m-1 ; j>=0 ; j--){
				cin >> c; obj[i] |= (c=='1' ? (1<<j) : 0);
			}
		}
		memset(dp, -1, sizeof dp); cout << solve(0,0) << endl;
	}
}