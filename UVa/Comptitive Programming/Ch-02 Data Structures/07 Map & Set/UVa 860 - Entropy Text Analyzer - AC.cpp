#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;

map<string, int> p;
map<string, int>::iterator it;
string puncs = ",.:;!?\"() \t\n";

// count number of words
int parseWords(const string& text) {
	int lambda = 0;
	stringstream sstr(text);
	string word;
	while (sstr >> word) {
		lambda++;
		if (p.count(word)) p[word]++;
		else p[word] = 1;
	}
	return lambda;
}

int isPunc(char c) {
	for (int i = 0; i < puncs.length(); i++) {
		if (puncs[i] == c) return true;
	}
	return false;
}

int main() {
	bool end = false;
	while (end == false) {
		p.clear();
		string word, text;
		while (cin >> word) {
			if (word == "****END_OF_TEXT****") break;
			if (word == "****END_OF_INPUT****") {
				end = true; break;
			}
			
			for (int i = 0; i < word.size(); i++) {
				if (!isPunc(word[i])) {
					if (isupper(word[i])) word[i] += 'a' - 'A';
				}
				else word[i] = ' ';
			}
			word += ' ';
			text += word;
		}
		if (end == true) break;
		int lambda = parseWords(text);

		double Et, Emax, Erel;

		Et = 0;
		for (it = p.begin(); it != p.end(); it++) {
			double pi = it->second;
			Et += pi*(log10(lambda) - log10(pi));
		}
		Et  *= 1.0 / (double)lambda;
		Emax = log10(lambda);
		Erel = (Et / Emax) * 100;
		printf("%d %.1lf %.0lf\n", lambda, Et, Erel);
	}
}