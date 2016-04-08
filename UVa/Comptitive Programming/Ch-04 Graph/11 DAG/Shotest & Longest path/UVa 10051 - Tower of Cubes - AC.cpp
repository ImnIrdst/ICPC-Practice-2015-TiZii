#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 6 * 500 + 10;

struct box{
	int id, top, down; string topface;
	box(int id = 0, int top = 0, int down = 0, const string& face = "")
		:id(id), top(top), down(down), topface(face){}
}boxes[MAX];

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; vi vis, ord, par; int n, cs = 1;

void toposort(int u){
	if (vis[u]) return; vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++){
		toposort(adj[u][i]);
	}
	ord.push_back(u);
}

int main(){
	while (cin >> n && n){
		int f, b, l, r, t, d; n = n * 6;  // d is for down (bottom)
		for (int i = n - 1, j = 1; i >= 0; j++){
			cin >> f >> b >> l >> r >> t >> d;
			boxes[i] = box(j, f, b, "front"); i--;
			boxes[i] = box(j, b, f, "back"); i--;
			boxes[i] = box(j, l, r, "left"); i--;
			boxes[i] = box(j, r, l, "right"); i--;
			boxes[i] = box(j, t, d, "top"); i--;
			boxes[i] = box(j, d, t, "bottom"); i--;
		}

		adj.assign(n, vi());
		for (int i = 0; i < n; i++){
			for (int j = i + 6 - (i % 6); j < n; j++){
				if (boxes[i].top == boxes[j].down){
					adj[i].push_back(j);
				}
			}
		}

		ord.clear();
		vis.assign(n, 0);
		for (int u = 0; u < n; u++){
			if (!vis[u]) toposort(u);
		}

		int lgstid = -1;
		int longest = -1;
		vis.assign(n, 0);
		par.assign(n, -1);
		while (!ord.empty()){
			int u = ord.back(); ord.pop_back();
			for (int i = 0; i < adj[u].size(); i++){
				int v = adj[u][i];
				if (vis[v] < vis[u] + 1){
					vis[v] = vis[u] + 1; par[v] = u;
					if (vis[v] > longest) longest = vis[v], lgstid = v;
				}
			}
		}

		vi ans; int v = lgstid;
		while (v != -1) ans.push_back(v), v = par[v];


		if (cs != 1) cout << endl;
		cout << "Case #" << cs++ << endl << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++){
			box u = boxes[ans[i]];
			cout << u.id << " " << u.topface << endl;
		}
	}
}
