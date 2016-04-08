#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> w;

string decToSkew(int n) {
	int id = 0; string ret = "";
	for (int i = 0; i < w.size(); i++) {
		if (w[i] > n) {
			id = i; break;
		}
	}
	while (--id) {
		ret += '0' + n / w[id];
		n = n % w[id];
	}
	return ret;
}

int main() {
	for (int i = 1; i < (1 << 30); i *= 2)
		w.push_back(i - 1);

	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		if (n == 0) {
			cout << "0 []" << endl; continue;
		}

		string sk = decToSkew(n);
		reverse(sk.begin(), sk.end());
		
		string com = "";
		cout << n << " [";
		for (int i = 0; i < sk.size(); i++) {
			if (sk[i] != '0') {
				cout << com << i; com = ",";
			}
			if (sk[i] == '2') {
				cout << com << i;
			}
		}cout << "]" << endl;
	}
}