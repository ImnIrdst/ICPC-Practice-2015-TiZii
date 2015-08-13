#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define INF (int)1e9

using namespace std;

int cost[110][110], dp[110][110], n, m;

int solve(int i , int q){
	int ans=INF;
	if(i==0) return 0;
	if(q<0) return INF;
	if(dp[i][q]!=-1) return dp[i][q];
	for(int j=0 ; j<n ; j++){
		if(cost[j][i]!=INF)
			ans=min(ans, solve(j,q-1)+cost[j][i]);
	}
	return dp[i][q]=ans;
}

map<string, int> mp;

int main(){
	int tc,t=1; cin >> tc; 
	while(tc--){
		cin >> n; mp.clear();
		for(int i=0 ; i<110 ; i++)
			for(int j=0 ;  j<110 ;j++)
				cost[i][j]=INF, dp[i][j]=-1;
		string tmp; 
		for(int i=0 ; i<n ; i++){
			cin >> tmp; mp[tmp]=i;
		}
		cin >> m;
		string tmp1, tmp2; int c;
		for(int i=0 ; i<m ; i++){
			cin >> tmp1 >> tmp2 >> c;
			cost[mp[tmp1]][mp[tmp2]]=min(c,cost[mp[tmp1]][mp[tmp2]]);
		}
		int qn; cin >> qn;
		cout << "Scenario #" << t++ << endl;
		for(int i=0 ; i<qn ; i++){
			int q; cin >> q; if(q) q=((q%n)?(q%n):n);
			int ans=solve(n-1, q);
			if(ans>=INF) cout << "No satisfactory flights" << endl;
			else cout << "Total cost of flight(s) is $" << ans << endl;
		}
		if(tc!=0) cout << endl;
	}
	return 0;
}