#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi; int n, t;

int dp[200+10][2], uniq[200+10][2]; vvi adj;

int solve(int u, bool invite){
	int& dpp=dp[u][invite];
	if(dpp != -1) return dpp;
	uniq[u][invite] = true;
	
	dpp = 0;
	if(invite == false){
		for(int i=0 ; i<adj[u].size() ; i++){
			int v = adj[u][i];
			int inviteCnt = solve(v,true)+1;
			int notInviteCnt = solve(v, false);
			if( inviteCnt > notInviteCnt )
				dpp += dp[v][true]+1, uniq[u][invite] &= uniq[v][true];
			else if( notInviteCnt > inviteCnt )
				 dpp += dp[v][false], uniq[u][invite] &= uniq[v][false];
			else dpp += dp[v][false], uniq[u][invite]  = false;
		}
	}
	if(invite == true){
		for(int i=0 ; i<adj[u].size() ; i++){
			int v = adj[u][i];
			dpp += solve(v,false);
			uniq[u][invite] &= uniq[v][false];
		}
	}
	return dpp;
}

int main(){
	int cs=1;
	while(cin >> n && n){
		adj.assign(n, vi());
		map<string, int> mp;
		string name, boss; t=1;
		cin >> name; mp[name]=0;
		for(int i=0 ; i<n-1 ; i++){
			cin >> name >> boss;
			if(!mp.count(name)) mp[name]=t++;
			if(!mp.count(boss)) mp[boss]=t++;
			adj[mp[boss]].push_back(mp[name]);
		}
		memset(dp, -1, sizeof dp); 
		
		bool uniqq = true; int ans;
		int inviteCnt = solve(0,true)+1;
		int notInviteCnt = solve(0, false);
		if( inviteCnt > notInviteCnt )
			 ans = inviteCnt, uniqq &= uniq[0][true];
		else if( notInviteCnt > inviteCnt )
			 ans = notInviteCnt, uniqq &= uniq[0][false];
		else ans = notInviteCnt, uniqq  = false;
		//cout << "Case " << cs++ << ": " << endl;
		cout << ans << " " << (uniqq ? "Yes" : "No" ) << endl;
	}
}