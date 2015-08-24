#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int tc;
	int cs = 1;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;

		vector<int> team(n);
		for (int i = 0; i < n; i++) {
			cin >> team[i];
		}

		cout << "Case " << cs++ << ": " << team[n / 2] << endl;
	}
}