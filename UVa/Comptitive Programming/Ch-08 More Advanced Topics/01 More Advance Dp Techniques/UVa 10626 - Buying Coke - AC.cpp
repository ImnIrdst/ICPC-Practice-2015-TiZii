#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int INF = 1e9       ;//Max long long

int dp[150+5][100+100][50+50], c, tot;

//calc ans using dp+bitmask and simulation
int solve(int coke, int n5, int n10){
	if(coke==c) return 0;
	int& dpp  = dp[coke][n5][n10]; if(dpp != -1) return dpp;

	dpp = INF; int n1 = tot - coke*8 - n5*5 - n10*10;
	if(n1  >= 8)          dpp = min(dpp,8+solve(coke+1, n5  , n10   ));
	if(n5  >= 1 && n1>=3) dpp = min(dpp,4+solve(coke+1, n5-1, n10   ));
	if(n10 >= 1 && n1>=3) dpp = min(dpp,4+solve(coke+1, n5+1, n10-1 ));
	if(n5  >= 2)          dpp = min(dpp,2+solve(coke+1, n5-2, n10   ));
	if(n10 >= 1)          dpp = min(dpp,1+solve(coke+1, n5  , n10-1 ));
	return dpp;
}
int main(){
    int tc,cs=1; cin >> tc;
    while(tc--){
    	//initialize and input
    	int n1, n5, n10;
        cin >> c >> n1 >> n5 >> n10;
        tot = n1 + 5*n5 + 10*n10;
        //calc and print ans
		memset(dp,-1,sizeof dp);
       	printf("%d\n", solve(0,n5,n10));
    }
}
