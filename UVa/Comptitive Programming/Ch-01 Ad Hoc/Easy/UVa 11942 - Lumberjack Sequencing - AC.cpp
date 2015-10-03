#include <iostream>

using namespace std;

typedef long long int64;

int main() {
	int tc;
	cin >> tc;
	cout << "Lumberjacks:" << endl;
	while (tc--) {
		int a[10], n = 10;
		for (int i = 0; i < n; i++) cin >> a[i];

		int inc = true;
		for (int i = 1; i < n; i++)
			if (a[i] < a[i - 1]) inc = false;

		int dec = true;
		for (int i = 1; i < n; i++)
			if (a[i] > a[i - 1]) dec = false;

		if (inc || dec) cout << "Ordered" << endl;
		else cout << "Unordered" << endl;
	}
}