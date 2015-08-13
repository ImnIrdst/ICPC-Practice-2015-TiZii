#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct pt{ double x,y; 
	pt(double x=0, double y=0):x(x), y(y){}
};

typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<pt > vpt;

vvi adj; vi owner, vis; vpt g, h; int n,m; double s,v;

double dist(pt a, pt b){ return hypot(a.x-b.x,a.y-b.y); }

int altpath(int u){
	if(vis[u]) return 0; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(owner[v]==-1 || altpath(owner[v])){
			owner[v]=u; return 1;
		}
	}
	return 0;
}

int main(){
	while(cin >> n >> m >> s >> v){
		adj.assign(n+m,vi()); 
		g.resize(n); h.resize(m);
		for(int i=0 ; i<n ; i++) cin >> g[i].x >> g[i].y;
		for(int i=0 ; i<m ; i++) cin >> h[i].x >> h[i].y;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(dist(g[i],h[j])/v <= s) adj[i].push_back(n+j);
			}
		}
		int ans=0; owner.assign(n+m,-1);
		for(int u=0 ; u<n ; u++){
			vis.assign(n,0); ans+=altpath(u);
		}
		cout << n-ans << endl;
	}
	return 0;
}
