#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct pt{ int x, y;
	pt(int x=0, int y=0, int d=0):x(x), y(y){}
};

const int MAX = 1e2+10;

typedef vector<int> vi;
typedef vector<vi > vvi;

pt obs[MAX]; vvi adj; vi vis;
double grid[MAX][MAX]; // Contain Distance to Nearest Obstecle
int di[]={-1,+1,-0,+0,-1,+1,+1,-1};
int dj[]={-0,+0,-1,+1,-1,+1,-1,+1}, L, W, n;

double dist2(const pt& a, const pt& b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int topWall;
int bottomWall;
void buildGraph(double lim){
	adj.assign(n+2,vi());
	
	topWall=n;
	bottomWall=n+1;
	for(int i=0 ; i<n ; i++) {
		if(obs[i].y-2*lim<0) adj[topWall].push_back(i);
		if(obs[i].y+2*lim>W) adj[i].push_back(bottomWall);
	
		for(int j=i+1 ; j<n ; j++){
			if(dist2(obs[i], obs[j])<2*lim*2*lim){
				adj[i].push_back(j), adj[j].push_back(i);
			}
		}
	}
}

bool dfs(int u){
	if(vis[u]) return 0; vis[u]=true;
	if(u==bottomWall) return true;
	bool ret=false;
	for(int i=0 ; i<adj[u].size() && !ret ; i++){
		ret |= dfs(adj[u][i]);
	}
	return ret;
}

bool wallsAreConnected(){
	vis.assign(n+2,0); 
	return dfs(topWall);
}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while(tc--){
		cin >> L >> W >> n; 
		for(int i=0 ; i<n ; i++){
			cin >> obs[i].x >> obs[i].y;
		}

		int iters=40;
		double lo=0, hi=W/2.0, mid;
		while(fabs(lo-hi)>1e-9 && iters--){
			mid = (lo+hi)/2;
			buildGraph(mid);
			if(wallsAreConnected()) hi=mid; else lo=mid;
		}

		printf("Maximum size in test case %d is %.4lf.\n", cs++, 2*lo);
	}
}