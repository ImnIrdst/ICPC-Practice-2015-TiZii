#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Pt{
	int x, y;
	Pt(int x = 0, int y = 0):x(x), y(y){}
};

struct Rect{
	Pt a, b;
	Rect(Pt a = Pt(0, 0), Pt b = Pt(0, 0))
		:a(a), b(b){}
};

bool pointInRect(Rect rect, Pt pt){
	return rect.a.x < pt.x && pt.x < rect.b.x
		&& rect.a.y < pt.y && pt.y < rect.b.y;
}

vector<Rect> rects; vector<Pt> points;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; vi owner, vis; int n, b, cs = 1;

int altpath(int u){
	if (vis[u]) return 0; vis[u] = 1;
	for (int i = 0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if (owner[v] == -1 || altpath(owner[v])){
			owner[v] = u; return 1;
		}
	}
	return 0;
}

int main(){
	while (cin >> n && n){
		Rect rect; b = n; rects.clear();
		for (int i = 0; i < n; i++){
			cin >> rect.a.x >> rect.b.x;
			cin >> rect.a.y >> rect.b.y;
			rects.push_back(rect);
		}

		Pt pt; points.clear();
		for (int i = 0; i < b; i++){
			cin >> pt.x >> pt.y; points.push_back(pt);
		}

		adj.assign(n, vi());
		for (int i = 0; i<n; i++){
			for (int j = 0; j < b; j++){
				if (pointInRect(rects[i], points[j])){
					adj[i].push_back(n + j);
				}
			}
		}

		map<char, int> ans;
		for (int u = 0; u < n; u++){
			for (int i = 0; i < adj[u].size(); i++){
				int v = adj[u][0]; 
				adj[u].erase(adj[u].begin());
				int MCBM = 0; owner.assign(n + b, -1);
				for (int u = 0; u<n; u++){
					vis.assign(n, 0); MCBM += altpath(u);
				}
				if (MCBM != n) ans[u + 'A'] = v + 1 - b ;
				adj[u].push_back(v);
			}
		}
		
		cout << "Heap " << cs++ << endl;
		if (ans.size() == 0) 
			cout << "none" << endl << endl;
		else {
			map<char, int>::iterator it;
			for(it = ans.begin(); it!=ans.end() ; it++){
				if (it != ans.begin()) cout << " ";
				cout << "(" << it->first << "," << it->second << ")";
			} cout << endl << endl;
		}
	}
	return 0;
}
