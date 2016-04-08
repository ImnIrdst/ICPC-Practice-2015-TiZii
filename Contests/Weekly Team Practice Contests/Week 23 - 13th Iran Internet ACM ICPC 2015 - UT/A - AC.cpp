#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> st, ans; vector<int> a;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n; 
		int m; cin >> m;

		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		st.clear();
		for (int i = 0; i < m; i++) {
			int u; cin >> u; st.insert(u);
		}

		ans.clear();
		for (int i = 0; i < n; i++) {
			if (!st.count(v[i])) ans.insert(v[i]);
		}
		
		if (ans.size()) {
			set<int>::iterator it = ans.begin();
			cout << *it; it++;
			for (it ; it != ans.end(); it++) {
				cout << ',' << *it;
			}cout << endl;
		}
		else cout << endl;
	}
}