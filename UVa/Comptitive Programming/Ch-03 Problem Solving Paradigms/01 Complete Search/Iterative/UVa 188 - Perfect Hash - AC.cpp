#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> words; vector<int> w; int C;

bool resolved() {
	int n = words.size();
	for (int i = 0; i < words.size(); i++) {
		for (int j = i + 1; j < words.size(); j++) {
			if ((C / w[i]) % n == (C / w[j]) % n) {
				C = min((C / w[i] + 1)*w[i], (C / w[j] + 1)*w[j]);
				return false;
			}
		}
	}
	return true;
}

int main() {
	string line;
	while (getline(cin, line)) {
		words.clear(); w.clear();
		stringstream sstr(line);
		
		string word;
		while (sstr >> word) 
			words.push_back(word);

		for (int i = 0; i < words.size(); i++) {
			w.push_back(0);
			
			for (int j = 0; j < words[i].length(); j++)
				w[i] *= 32, w[i] += (words[i][j] - 'a' + 1);
		}

		C = 0x7FFFFFFF;
		for (int i = 0; i < words.size(); i++) {
			C = min(C, w[i]); // C Must be at least multiply of w[i]
		}

		while (!resolved());
		cout << line << endl << C << endl << endl;
	}
}