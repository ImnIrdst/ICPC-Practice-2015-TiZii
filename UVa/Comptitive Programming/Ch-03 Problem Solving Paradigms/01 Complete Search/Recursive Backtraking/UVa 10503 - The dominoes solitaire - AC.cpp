#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9

using namespace std;

int n,m,a[20],b[20],vis[20]; // vis -> visited, a -> heads, b -> tails

int solve(int prev, int cnt, int flag){
	if(cnt==n) if(flag) return a[m+1]==b[prev]; else return a[m+1]==a[prev];
	vis[prev]=1;
	for(int i=1 ; i<=m ; i++){
		if(flag && a[i]==b[prev] && !vis[i]){
			if(solve(i,cnt+1,1)) return 1;
		}
		if(flag && b[i]==b[prev] && !vis[i]){
			if(solve(i,cnt+1,0)) return 1;
		}
		if(!flag && a[i]==a[prev] && !vis[i]){
			if(solve(i,cnt+1,1)) return 1;
		}
		if(!flag && b[i]==a[prev] && !vis[i]){
			if(solve(i,cnt+1,0)) return 1;
		}
	}
	vis[prev]=0;
	return 0;
}

int main(){
	while(cin >> n && n){
		cin >> m; cin >> a[0] >> b[0] >> a[m+1] >> b[m+1];
		for(int i=1 ; i<=m ; i++) cin >> a[i] >> b[i];
		memset(vis,0,sizeof vis);
		cout << (solve(0,0,1) ? "YES" : "NO" ) << endl;
	}
	return 0;
}