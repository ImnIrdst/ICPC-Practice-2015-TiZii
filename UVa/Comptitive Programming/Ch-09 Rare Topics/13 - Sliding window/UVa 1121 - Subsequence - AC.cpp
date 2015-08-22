#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 10;

int seq[MAX], n , s;

int main() {
	while (cin >> n >> s) {
		for (int i = 0; i < n; i++) 
			cin >> seq[i];

		int sum = seq[0],  ans = 1e9;
		for (int i = 0, j = 0; i < n && j < n;) {
			if (sum >= s) 
				ans = min(ans, j - i + 1);
			if (sum >= s && i < j)
				sum -= seq[i], i++;
			else if(sum < s)
				if (++j < n) sum += seq[j];
		}
		if (ans == 1e9) ans = 0;
		cout << ans << endl;
	}
}