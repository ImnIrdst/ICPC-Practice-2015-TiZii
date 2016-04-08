#include <iostream>

using namespace std;

typedef long long int64;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int64 n; cin >> n;
		int64 tot = (n*(n + 1)) / 2 ;
		cout << tot <<  " ";
		int64 odds = ((n))*((n));
		cout << odds <<  " ";
		int64 even = (n)*(n)+(n);
		cout << even << endl;
	}
}