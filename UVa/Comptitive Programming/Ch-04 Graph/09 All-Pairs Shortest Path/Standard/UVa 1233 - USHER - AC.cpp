#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 500 + 10;

int adj[SIZE][SIZE], pari[SIZE], n;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int b, p, q;
		cin >> b >> p >> q;
		memset(adj, 0x1f, sizeof adj);
		for (int i = 0; i < q; i++){
			cin >> pari[i]; adj[0][pari[i]] = 0;
		}

		
		for (int u = 1; u <= p; u++){
			int m; cin >> m;
			for (int j = 0; j < m; j++){
				int w, v; cin >> w >> v;
				adj[u][v] = min(adj[u][v], w);
			}
		}
		for (int k = 0; k <= p; k++){
			for (int i = 0; i <= p; i++){
				for (int j = 0; j <= p; j++){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}

		int minn = adj[0][0];
		
		int cur = 0;
		int ans = 0;
		while (true) {
			if ((cur + minn) >= b) break;
			cur = cur + minn - 1; ans++;
		}

		cout << ans << endl;
	}
}