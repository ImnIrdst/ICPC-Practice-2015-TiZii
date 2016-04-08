#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n; cin >> n;
		vector<int> ropes(n, 0);
		for (int i = 0; i < n; i++){
			cin >> ropes[i];
		}

		sort(ropes.begin(), ropes.end(), ::greater<int>());

		int ans = 0, Min = 1e9;
		for (int i = 0; i < n; i++){
			Min = min(Min, ropes[i]);
			ans = max(ans, Min * (i + 1));
		}

		cout << ans << endl;
	}
}