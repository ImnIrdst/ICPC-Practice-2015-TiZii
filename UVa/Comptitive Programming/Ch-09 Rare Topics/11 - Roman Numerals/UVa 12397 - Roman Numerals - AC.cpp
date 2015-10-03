#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> cost;
map<char, int> rtoa;
map<int, string> ator;


void init() {
	ator[1]    = "I";
	ator[1000] = "M"; ator[900] = "CM";
	ator[100]  = "C"; ator[90]  = "XC";
	ator[10]   = "X"; ator[9]   = "IX";
	ator[500]  = "D"; ator[400] = "CD";
	ator[50]   = "L"; ator[40]  = "XL";
	ator[5]    = "V"; ator[4]   = "IV";

	rtoa['I'] = 1; rtoa['X'] = 10; rtoa['C'] = 100;
	rtoa['V'] = 5; rtoa['L'] = 50; rtoa['D'] = 500; rtoa['M'] = 1000;

	cost['I'] = 1; cost['V'] = 2; cost['X'] = 2;
	cost['L'] = 2; cost['C'] = 2; cost['D'] = 3; cost['M'] = 4;
}

string AtoR(int A) {
	string ret = ""; 
	map<int, string>::reverse_iterator it;
	for (it = ator.rbegin(); it != ator.rend(); it++) {
		while (A >= it->first) {
			ret += it->second; A -= it->first;
		}
	}
	return ret;
}

int RtoA(string R) {
	int value = 0; 
	for (int i = 0; i < R.length(); i++) {
		if (i + 1 < R.length() && rtoa[R[i]] < rtoa[R[i + 1]])
			value += rtoa[R[i + 1]] - rtoa[R[i]], i++;
		else value += rtoa[R[i]];
	}
	return value;
}

int main() {
	int n; init();
	while (cin >> n) {
		string roman = AtoR(n);
		
		int ans = 0;
		for (int i = 0; i < roman.length(); i++) {
			ans += cost[roman[i]];
		}

		cout << ans << endl;
	}
}