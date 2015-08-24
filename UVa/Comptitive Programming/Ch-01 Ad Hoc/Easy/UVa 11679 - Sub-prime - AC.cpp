#include <iostream>

using namespace std;

const int Max = 20 + 10;

int main(){
	int b, n;
	while (cin >> b >> n && (n || b)){
		int balance[Max];
		for (int i = 0; i < b; i++) cin >> balance[i];

		int u, v, w;
		for (int i = 0; i < n; i++){
			cin >> u >> v >> w; u--, v--;
			balance[u] -= w; balance[v] += w;
		}

		int ok = true;
		for (int i = 0; i < b; i++){
			if (balance[i] < 0) ok = false;
		}

		if (ok) cout << "S" << endl;
		else    cout << "N" << endl;
	}
}