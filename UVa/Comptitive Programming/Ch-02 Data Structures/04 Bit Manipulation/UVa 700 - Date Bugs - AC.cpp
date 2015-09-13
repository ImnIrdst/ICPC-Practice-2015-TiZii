#include <iostream>
#include <algorithm>

using namespace std;

int bug[20 + 10], date[20 + 10];

int main() {
	int n, cs = 1;
	while (cin >> n && n) {
		int a, b, year = 0;
		for (int i = 0; i < n; i++) {
			cin >> date[i] >> a >> b; bug[i] = b - a;
			year = max(year, date[i]);
		}

		bool ok = true;
		for (year = year; year < 10000; year++) {
			ok = true;
			for (int i = 0; i < n && ok; i++) {
				if ((year - date[i]) % bug[i] != 0) ok = false;
			}
			if (ok == true) break;
		}
		//if (year == 10000) ok = false;
		cout << "Case #" << cs++ << ":" << endl;
		if (ok == false) cout << "Unknown bugs detected." << endl << endl;
		if (ok == true ) cout << "The actual year is " << year << "." << endl << endl;
	}
}