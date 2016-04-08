#include <iostream>
#include <vector>
#include <queue>
#include <cstring> 
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; vi vis; int n; 

int dcmp(double a, double b){
	return (fabs(a - b) < 1e-9 ? 0 : ( a < b ? -1 : 1));
}

int main(){
	while (cin >> n){
		char u[256 + 10], v;
		vector<double> p(256+10);
		adj.assign(265 + 10, vi());
		for (int i = 0; i < n; i++){
			cin >> v; cin >>  p[v] >> u;
			for (int i = 0; i < strlen(u); i++){
				adj[u[i]].push_back(v);
			}
		}

		
		queue<int> q; q.push('*');
		vis.assign(256+10, 0); vis['*'] = 1;
		
		while (!q.empty()){
			int u = q.front(); q.pop();

			for (int i = 0; i < adj[u].size(); i++){
				int v = adj[u][i];
				if (!vis[v]) vis[v] = vis[u] + 1, q.push(v);
			}
		}

		double Max = 0; char ans;
		for (int i = 0; i < vis.size(); i++){
			if (vis[i]) vis[i]--;  else continue;
			double assd = p[i] * pow(0.95, vis[i]);
			if (dcmp(Max, p[i] * pow(0.95, vis[i])) < 0){
				Max = p[i] * pow(0.95, vis[i]); ans = i;
			}
		}

		cout << "Import from " << ans << endl;
	}
}