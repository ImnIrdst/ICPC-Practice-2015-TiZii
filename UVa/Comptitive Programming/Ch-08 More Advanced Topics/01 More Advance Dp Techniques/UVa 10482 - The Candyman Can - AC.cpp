#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAXC = 32+10    ;//Max Candies
const int MAXV = 32*20+10 ;//Max Candies a kid can have
const int INF = 1e9       ;//Max long long

int dp[MAXC][MAXV][MAXV], w[MAXC], n, sum[MAXC];

//calc maximum difrance
int max3(int k1, int k2, int k3){
	return max(k1,max(k2,k3));
}
int min3(int k1, int k2, int k3){
	return min(k1,min(k2,k3));
}
//calc ans using dp+bitmask and simulation
int solve(int i, int k1, int k2){ int k3=sum[i]-k1-k2;
	if(i==n) return k1-k2;
	int& dpp  = dp[i][k1][k2]; if(dpp  != -1) return dpp ;
	
	dpp = INF;
	//giving i candy to kid 1
	dpp = min(dpp,solve(i+1, max3(k1+w[i],k2,k3), min3(k1+w[i],k2,k3)));
	//giving i candy to kid 2
	dpp = min(dpp,solve(i+1, max3(k1,k2+w[i],k3), min3(k1,k2+w[i],k3)));
	//giving i candy to kid 3
	dpp = min(dpp,solve(i+1, max3(k1,k2,k3+w[i]), min3(k1,k2,k3+w[i])));
	
	return dpp;
}
void memsetdp(){
	for(int i=0; i<=n; i++)
        for(int j=0; j<=sum[n]; j++)
            for(int k=0; k<=sum[n]; k++)
                dp[i][j][k]=-1;
}
int main(){
    int tc,cs=1; cin >> tc;
    while(tc--){
    	//initialize and input
        cin >> n; sum[0]=0;
        for(int i=0, s=0 ; i<n ; i++){
        	cin >> w[i]; sum[i+1]=w[i]+s; s=sum[i+1];
        }
        //calc and print ans
		memsetdp();//(dp,-1,sizeof dp);
       	printf("Case %d: %d\n", cs++, solve(0,0,0));
    }
}
