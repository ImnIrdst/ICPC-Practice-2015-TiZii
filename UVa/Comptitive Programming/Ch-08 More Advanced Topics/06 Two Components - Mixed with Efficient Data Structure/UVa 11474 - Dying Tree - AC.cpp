#include <iostream>
#include <vector>

using namespace std;

struct pt{ int x, y;
	pt(int x=0, int y=0): x(x), y(y){}
};

typedef vector<int>  vi; 
typedef vector<vi >  vvi;
typedef vector<pt >  vpt;
typedef vector<vpt > vvpt;

int n, m, k, d, b; vvpt trees; vvi adj; vi vis;

int dist2(pt& a, pt& b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool canReach(vpt& a, vpt& b, bool isDoctor){
	int lim = (isDoctor ? d : k);
	for(int i=0 ; i<a.size() ; i++){
		for(int j=0 ; j<b.size() ; j++){
			if(dist2(a[i], b[j]) <= lim*lim) return true;
		}
	}
	return false;
}

bool dfs(int u){
	if(vis[u]) return false; vis[u]=true;
	if(u < m ) return true;

	bool ret=false;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v = adj[u][i];
		ret = (ret || dfs(v));
	}
	return ret;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> m >> k >> d;

		int x, y; trees.assign(n+m, vpt());
		for(int i=0 ; i<m ; i++){
			cin >> x >> y; trees[i].push_back(pt(x,y));
		}
		for(int i=0 ; i<n ; i++){ cin >> b;
			for(int j=0 ; j<b ; j++){
				cin >> x >> y; trees[i+m].push_back(pt(x, y));
			}
		}

		adj.assign(n+m, vi());
		for(int i=0 ; i<n+m ; i++){
			for(int j=0 ; j<n+m ; j++){
				if(canReach(trees[i], trees[j], i<m || j<m))
					adj[i].push_back(j);
			}
		}

		vis.assign(n+m, false); bool ok = dfs(m);
		if(ok) cout << "Tree can be saved :)" << endl;
        else   cout << "Tree can't be saved :(" << endl;
	}
}