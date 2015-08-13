#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct pt{ int x, y, p;
	pt(int x=0, int y=0, int p=0): x(x), y(y), p(p) {}
};
typedef vector<int> vi;
typedef vector<vi > vvi;

int a, b, r; vector<pt> pts;

bool teamNum(int c){
	return (pts[b].x-pts[a].x)*(pts[c].y-pts[a].y)
		  -(pts[b].y-pts[a].y)*(pts[c].x-pts[a].x) > 0;
}

int dist2(int i, int j){
	return (pts[i].x-pts[j].x)*(pts[i].x-pts[j].x)
		  +(pts[i].y-pts[j].y)*(pts[i].y-pts[j].y);
}

vvi adj; vi owner, vis; int n,m;

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
	int nn, cs=1;
	while(cin >> nn && nn){
		int x, y, p; pts.clear();
		
		for(int i=0 ; i<nn ; i++){
			cin >> x >> y >> p; pts.push_back(pt(x,y,p));
		}
		cin >> a >> b >> r; a--, b--;

		vector<int> team[2];
		for(int i=0 ; i<nn ; i++){
			if(pts[i].p!=0) team[teamNum(i)].push_back(i);
		}
		n = team[0].size(), m = team[1].size();
		if(n > m) team[0].swap(team[1]), swap(n,m);
		
		adj.assign(n+b, vi());
		for(int i=0 ; i<n ; i++){ int u=team[0][i];
			for(int j=0 ; j<m ; j++){ int v=team[1][j];
				if(dist2(u, v) < r*r && pts[u].p > pts[v].p) adj[i].push_back(j+n);
			}
		}

		int ans=0; owner.assign(n+m,-1);
		for(int u=0 ; u<n ; u++){
			vis.assign(n,0); ans+=altpath(u);
		}
		cout << "Case " << cs++ << ": " << ans << endl;
	}
}