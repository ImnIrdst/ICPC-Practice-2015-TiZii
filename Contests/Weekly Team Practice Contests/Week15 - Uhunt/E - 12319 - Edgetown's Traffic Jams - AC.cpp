#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int Max = 1e2 + 10;

int adj1[Max][Max], adj2[Max][Max];

void init() {
	for (int i = 0; i < Max; i++) {
		for (int j = 0; j < Max; j++) {
			adj1[i][j] = adj2[i][j] = 1e6;
		}
		adj1[i][i] = adj2[i][i] = 0;
	}
}

int main() {
	int n;
	while (cin >> n && n) {
		string line;
		int u, v, m; init();
		for (int i = 0; i < n; i++) {
			cin >> u;  u--;
			getline(cin, line);
			stringstream sstr(line);
			while (sstr >> v) {
				v--; adj1[u][v] = 1; 
			}
		}

		m = n;//cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> u;  u--;
			getline(cin, line);
			stringstream sstr(line);
			while (sstr >> v) {
				v--; adj2[u][v] = 1;
			}
		}
		
		
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					adj1[i][j] = min(adj1[i][j], adj1[i][k] + adj1[k][j]);
				}
			}
		}

		
		for (int k = 0; k < m; k++) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					adj2[i][j] = min(adj2[i][j], adj2[i][k] + adj2[k][j]);
				}
			}
		}

		int a, b, ok = true; cin >> a >> b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a*adj1[i][j] + b < adj2[i][j]) 
					ok = false;
			}
		}
		if (ok) cout << "Yes" << endl;
		else	cout << "No" << endl;
	}
}
