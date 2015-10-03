#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int memo[100] = { 0 };

int powMod(int n, int b, int m) {
	if (b == 1) return (n)%m;

	int pwm = powMod(n, b / 2, m);
	if (b % 2 == 0) return (pwm*pwm) % m;
	if (b % 2 == 1) return (pwm*pwm*n) % m;
}

void init() {
	for (int n = 1; n < 99; n++) {
		memo[n] = (memo[n - 1] + powMod(n, n, 10)) % 10;
	}
}

int main() {
	string num; init();
	while (getline(cin, num) && num != "0") {
		if (num.length() >= 2) 
			num = num.substr(num.length() - 2, 2);

		stringstream sstr(num); int n; sstr >> n;

		cout << memo[n] << endl;
	}
}