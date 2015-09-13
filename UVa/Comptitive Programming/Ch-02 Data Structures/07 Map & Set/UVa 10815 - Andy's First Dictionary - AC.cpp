#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <sstream>
using namespace std;

int main() {
	string line;
	string word;
	set<string> dic;
	while (cin >> line) {
		for (int i = 0; i < line.length(); i++) {
			if (!isalpha(line[i])) line[i] = ' ';
			else if (isupper(line[i])) line[i] += 'a' - 'A';
		}
		stringstream sstr(line);
		while (sstr >> word) dic.insert(word);
	}

	set<string>::iterator it;
	for (it = dic.begin(); it != dic.end(); it++) {
		cout << *it << endl;
	}
}