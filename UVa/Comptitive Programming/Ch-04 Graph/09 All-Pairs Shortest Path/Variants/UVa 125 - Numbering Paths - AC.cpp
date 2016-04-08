#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 30 + 10;

int adj[SIZE][SIZE], n, m, cs = 0;

int main(){
	while (cin >> m){
		int u, v, n=0;
		
		memset(adj, 0, sizeof adj);
		for (int i = 0; i < m; i++){
			cin >> u >> v; adj[u][v] = 1;
			n = max(n, max(u, v));
		} n++;
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (adj[i][k] && adj[k][j]){
						adj[i][j] += adj[i][k] * adj[k][j];
					}
				}
			}
		}
		for (int k = 0; k < n; k++){
			if (adj[k][k] == 0) continue;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (adj[i][k] && adj[k][j]){
						adj[i][j] = -1;
					}
				}
			}
		}

		cout << "matrix for city " << cs++ << endl;
		if (m == 0) continue;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (j) cout << " ";
				cout << adj[i][j];
			}cout << endl;
		}
	}
}