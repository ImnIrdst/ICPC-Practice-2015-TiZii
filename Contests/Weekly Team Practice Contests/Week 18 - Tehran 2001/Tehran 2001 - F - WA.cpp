#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct pipe{
	int x, y, l, id;
	pipe(int x = 0, int y = 0, int l = 0, int id = 0)
		:x(x), y(y), l(l), id(id){}
	bool operator<(const pipe& op) const {
		return x < op.x;
	}
}; vector<pipe> pipes;

int isPointInPipe(int pid, int x, int y, int l){
	if (y < pipes[pid].y || y > pipes[pid].y + pipes[pid].l) return false;
	if (pipes[pid].x + 1 == x && pid + 1 < pipes.size() && pipes[pid + 1].x == x + l) return true;
}

vector<int> ply; // y coord of link of each pipe 
vector<int> pfy; // y coord of fill point of each pipe 

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		pipes.clear();
		int n, x, y, l, id; cin >> n;
		for (int i = 0; i < n; i++){
			cin >> x >> y >> l;
			pipes.push_back(pipe(x, y, l, i+1));
		}
		sort(pipes.begin(), pipes.end());
		ply.assign(n, -1);
		pfy.assign(n, -1);
		int m; 
		cin >> m;
		
		while (m--){
			cin >> x >> y >> l;
			for (int i = 0; i < n; i++){
				if (isPointInPipe(i, x, y, l)){
					ply[i] = max(ply[i], y); // check if (y > pipes[i].y)
				}
			}
		}

		cin >> id >> y;
		for (int i = 0; i < n; i++){
			if (pipes[i].id == id){
				id = i; break;
			}
		}

		pfy[id] = y;
		for (int i = id; i < n; i++){
			pfy[i] = max(pfy[id], pipes[i].y);
		}
		bool noSol = false;
		for (int i = 0; i < id; i++){
			if (pipes[i].y > pfy[id] || ply[i]==-1) {
				noSol = true; break;
			}
			pfy[i] = min(ply[i], pfy[id]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++){
			if (pfy[i] == -1) break;
			ans += pipes[i].y + pipes[i].l - pfy[i];
		}

		if (noSol == true) cout << "No Solution" << endl;
		if (noSol == false) cout << ans << endl;
	}
}