#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int StoI(const string& str) {
	stringstream sstr(str);
	int ret; sstr >> ret;
	return ret;
}

int main() {
	int tc;
	int cs = 1;
	cin >> tc;
	cin.ignore();
	while (tc--) {
		string line; getline(cin, line);
		cout << "Case " << cs++ << ": ";

		int i = 0; 
		while (i < line.length()) {
			char c = line[i]; i++;

			string num = "";
			while (isdigit(line[i]) && i<line.length()){
				num += line[i]; i++;
			}

			int n = StoI(num);
			for (int j = 0; j < n; j++) {
				cout << c;
			}
		}
		cout << endl;
	}
}