#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#define INF (int)1e9
#define p pair<int,int>
#define X first
#define Y second

using namespace std;

int n,s,e,t,adj[110][110],dp[110][1010]; map<int,int> mp; 

int solve(int pos, int cnt){
	if(cnt==t &&  mp[pos]) return 0;
	if(cnt==t && !mp[pos]) return -1*INF;
	int& dpp=dp[pos][cnt];
	if(dpp!=-1) return dpp;
	for(int i=1 ; i<=n ; i++){
		if(i!=pos) dpp=max(dpp,solve(i,cnt+1)+adj[pos][i]);
	}
	return dpp;
}

int main(){

	while(cin >> n >> s >> e >> t && (n || s || e || t) ){
		
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++){
				cin >> adj[i][j];
			}
		}
		mp.clear(); int tmp; memset(dp,-1,sizeof dp);
		for(int i=0 ; i<e ; i++){ cin >> tmp; mp[tmp]=1; }
		cout << solve(s,0) << endl;
	}
	return 0;
}