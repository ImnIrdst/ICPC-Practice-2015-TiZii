#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8 + 10;


int frontt[MAX], rightt[MAX], grid[MAX][MAX];


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int k; cin >> k;
		for (int i = 0; i < k; i++) cin >> frontt[i];
		for (int j = 0; j < k; j++) cin >> rightt[j];

		int Max = 0, Min = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				grid[i][j] = min(frontt[i], rightt[j]);
				Max += grid[i][j];
			}
		}

		int fused[MAX] = { 0 }, rused[MAX] = { 0 };
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (rightt[i] == frontt[j] && !rused[i] && !fused[j]) {
					Min += rightt[i];  rused[i] = true; fused[j] = true;
				}
			}
		}

		for (int i = 0; i < k; i++) {
			if (rused[i] == false) Min += rightt[i];
			if (fused[i] == false) Min += frontt[i];
		}


		cout << "Matty needs at least " << Min << " blocks, ";
		cout << "and can add at most " << Max - Min << " extra blocks." << endl;
		
		/*cout << endl;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}*/

	}
}