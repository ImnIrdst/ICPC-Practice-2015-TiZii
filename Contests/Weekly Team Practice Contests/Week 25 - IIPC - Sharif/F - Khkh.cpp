#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(NULL));
	int tc;
	cin >> tc;
	while (tc--) {
		cout << ((rand()) % 3 == 0 ? "YES" : "NO") << endl;;
	}
}