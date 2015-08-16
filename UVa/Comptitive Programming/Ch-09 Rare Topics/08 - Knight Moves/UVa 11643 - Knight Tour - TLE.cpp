#include <iostream>
#include <time.h>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e3+10;

struct pt{ int i, j, d, dh;
	pt(int i=0, int j=0, int d=0, int dh=0)
		:i(i), j(j), d(d), dh(dh){}
	bool operator<(const pt& a) const {
		if(dh==a.dh && d==a.d && j==a.j) return i>a.i;
		if(dh==a.dh && d==a.d) return j>a.j;
		if(dh==a.dh) return d>a.d;
		return dh>a.dh;
	}
}interests[16+1];

int n, m, vis[MAX][MAX], adj[16+1][16+1], step;
int di[] = {1, 1,-1,-1, 2, 2,-2,-2};
int dj[] = {2,-2, 2,-2, 1,-1, 1,-1};

int inRange(int i, int j){
	return (i>0 && i<=n && j>0 && j<=n && vis[i][j]!=step);
}

int h(const pt& a,const pt& b){
	int dx = abs(a.i-b.i), dy = abs(a.j-b.j);
	return min(max(dx ,dy/2), max(dx/2 ,dy));
}

int AStar(const pt& s, const pt& f){
	priority_queue<pt> q; q.push(s);

	pt u;
	while(!q.empty()){
		u = q.top(); q.pop(); 
		if(u.i == f.i && u.j==f.j) 
			return u.d;
		for(int dir=0 ; dir<8 ; dir++){
			pt v(u.i+di[dir], u.j+dj[dir], u.d+1);
			if( !inRange(v.i, v.j) ) continue;
			v.dh = v.d + h(v,f);
			vis[v.i][v.j]=step; q.push(v);
		}
	}
	return 1e9;
}

int dp[17][1<<17];

int TSP(int pos, int bit){
	int& dpp = dp[pos][bit];
	if(bit == (1<<m)-1) return adj[pos][0];
	if(dpp != -1) return dpp;

	dpp = 1e9;
	for(int i=0 ; i<m ; i++){
		if(!(bit&(1<<i))){
			dpp = min(dpp, TSP(i, bit|(1<<i))+adj[pos][i]);
		}
	}
	return dpp;
}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i=0 ; i<m ; i++){
			cin >> interests[i].i >> interests[i].j;
		}
		memset(vis, 0, sizeof vis); step=1;
		//clock_t start = clock();
		for(int i=0 ; i<m ; i++){
			for(int j=i+1 ; j<m ; j++){
				adj[i][j] = adj[j][i] = AStar(interests[i], interests[j]);
				step++;
			}
		}
		//cout << clock()-start << endl;
		memset(dp, -1, sizeof dp);
		cout << "Case " << cs++ << ": " << TSP(0, 1) << endl;
		//cout << clock()-start << endl;
	}
}