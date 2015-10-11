#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adjOrg, adjRev;
vi vis, ord, indeg, col;

map<string, int> mpsi;
vector<string> mpis, ans;

int n, tag;

int S2I(const string& str){
	if (mpsi.count(str))
		return mpsi[str];

	mpsi[str] = tag++;
	mpis.push_back(str);
	return mpsi[str];
}

void dfsOrg(int u){
	if (vis[u]) return; vis[u] = true;
	for (int i = 0; i < adjOrg[u].size(); i++){
		dfsOrg(adjOrg[u][i]);
	}
	ord.push_back(u);
}

int dfsRev(int u, int color){
	if (col[u]) return 0; col[u] = color;

	int ret = 1;
	for (int i = 0; i < adjRev[u].size(); i++){
		ret += dfsRev(adjRev[u][i], color);
	}
	return ret;
}

void dfsAns(int u){
	if (vis[u]) return; vis[u] = true;

	ans.push_back(mpis[u]);
	for (int i = 0; i < adjOrg[u].size(); i++){
		dfsAns(adjOrg[u][i]);
	}
}

int main(){
	while (cin >> n && n){
		cin.ignore();
		string line, u, v;
		adjOrg.assign(n, vi());
		adjRev.assign(n, vi());
		mpsi.clear(); mpis.clear();

		tag = 0; indeg.assign(n, 0);
		for (int i = 0; i < n; i++){
			getline(cin, line);
			stringstream sstr(line);
			sstr >> u;
			while (sstr >> v){
				//if (S2I(v) >= adjOrg.size() || tag >= adjOrg.size())
				//	adjOrg.push_back(vi());
				adjOrg[S2I(u)].push_back(S2I(v));
				adjRev[S2I(v)].push_back(S2I(u));
				//if (S2I(u) >= adjRev.size() || tag >= adjRev.size())
				//	adjRev.push_back(vi()), indeg.push_back(0);
			}
		}
		n = tag;

		ord.clear();
		vis.assign(n, 0);
		for (int u = 0; u < n; u++){
			if (!vis[u]) dfsOrg(u);
		}
		int color = 1;
		ans.clear();
		vis.assign(n, 0);
		col.assign(n, 0);
		while (!ord.empty()){
			int u = ord.back();

			if (!col[u]){
				int cnt = dfsRev(u, color);
				if (cnt > 1){
					for (int v = 0; v < n; v++){
						if (col[v] == color) dfsAns(v);
					}
				}
				color++;
			}
			ord.pop_back();
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++){
			if (i) cout << " "; cout << ans[i];
		} cout << endl;
	}
}