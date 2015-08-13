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
#define X first
#define Y second

using namespace std;

p a[15]; int n, dp[15][1<<15];

int abss(int a){ return (a>0 ? a : -1*a); }
int dist(p a, p b){ return abss(a.X-b.X)+abss(a.Y-b.Y); }

int solve(int pos, int bitset){
	if(bitset==(1<<n)-1) return dist(a[pos],a[0]);
	if(dp[pos][bitset]!=-1) return dp[pos][bitset];
	dp[pos][bitset]=INF;
	for(int i=0 ; i<n ; i++){
		if(!(bitset&(1<<i))){
			dp[pos][bitset]=min(dp[pos][bitset],solve(i,bitset|(1<<i))+dist(a[pos],a[i]));
		}
	}
	return dp[pos][bitset];
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> a[0].X >> a[0].Y; cin >> a[0].X >> a[0].Y;  cin >> n; n++;
		for(int i=1 ; i<n ; i++) cin >> a[i].X >> a[i].Y;
		memset(dp, -1, sizeof dp);
		cout << "The shortest path has length " << solve(0,1) << endl;
	}
	return 0;
}