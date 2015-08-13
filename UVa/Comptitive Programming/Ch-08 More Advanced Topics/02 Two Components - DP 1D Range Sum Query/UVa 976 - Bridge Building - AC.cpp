#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXD = 1e3+10, MAXB = 1e2+10;

int di[]={-1,+1,-0,+0};
int dj[]={+0,-0,+1,-1};
int vis[MAXD][MAXD]; char Map[MAXD][MAXD];
int BLen[MAXD], dp[MAXD][MAXB], n , m, b, s;

int inRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m && Map[i][j]=='#');
}

void dfs(int i, int j, const int c){//flood fill
	if(vis[i][j]) return; vis[i][j]=c;
	for(int k=0 ; k<4 ; k++) 
		if(inRange(i+di[k], j+dj[k])) dfs(i+di[k], j+dj[k], c);
}

int solve(int id, int rem){
	if(id>=m && rem==0) return 0;
	if(id>=m && rem!=0) return 1e9;

	int& dpp = dp[id][rem];
	if( dpp != -1 ) return dpp;
	
	dpp = 1e9;
	if( rem > 0 )  dpp = min(dpp, solve(id+s+1, rem-1)+BLen[id]);
	else return 0; dpp = min(dpp, solve(id+1, rem));
	return dpp;
}

int main(){
	while(cin >> n >> m){
		cin >> b >> s; //if(s==0) s=1;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++) cin >> Map[i][j];
		}
		memset(vis, 0, sizeof vis);
		dfs(0,0,1); dfs(n-1,m-1,2);
		for(int j=0 ; j<m ; j++){ int last1=0,i;
			for( i=0 ; i<n &&  vis[i][j]!=2 ; i++){
				if(vis[i][j]==1) last1 = i;
			}
			BLen[j]=i-last1-1;
		}
		memset(dp, -1, sizeof dp);
		cout << solve(0,b) << endl;
	}
}