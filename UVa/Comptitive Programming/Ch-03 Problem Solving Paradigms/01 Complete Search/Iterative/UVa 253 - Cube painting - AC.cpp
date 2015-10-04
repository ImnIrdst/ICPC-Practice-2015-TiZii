#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string first, second;

int rotation[24][6] = {
	{ 1, 2, 3, 4, 5, 6 },
	{ 1, 4, 2, 5, 3, 6 },
	{ 1, 5, 4, 3, 2, 6 },
	{ 1, 3, 5, 2, 4, 6 },
	{ 2, 6, 3, 4, 1, 5 },
	{ 2, 4, 6, 1, 3, 5 },
	{ 2, 1, 4, 3, 6, 5 },
	{ 2, 3, 1, 6, 4, 5 },
	{ 3, 1, 2, 5, 6, 4 },
	{ 3, 5, 1, 6, 2, 4 },
	{ 3, 6, 5, 2, 1, 4 },
	{ 3, 2, 6, 1, 5, 4 },
	{ 6, 5, 3, 4, 2, 1 },
	{ 6, 3, 2, 5, 4, 1 },
	{ 6, 2, 4, 3, 5, 1 },
	{ 6, 4, 5, 2, 3, 1 },
	{ 5, 1, 3, 4, 6, 2 },
	{ 5, 3, 6, 1, 4, 2 },
	{ 5, 6, 4, 3, 1, 2 },
	{ 5, 4, 1, 6, 3, 2 },
	{ 4, 6, 2, 5, 1, 3 },
	{ 4, 2, 1, 6, 5, 3 },
	{ 4, 1, 5, 2, 6, 3 },
	{ 4, 5, 6, 1, 2, 3 },
};

string Rot(int i) {
	string str="";
	for (int j = 0; j < 6; j++) {
		str += first[rotation[i][j] - 1];
	}
	return str;
}

int main() {
	string inp;
	while (cin >> inp) {
		first = inp.substr(0, 6);
		second = inp.substr(6);

		bool TRUE = false;
		for (int i = 0; i < 24; i++) {
			if (Rot(i) == second) {
				TRUE = true;  break;
			}
		}
		if (TRUE) cout << "TRUE" << endl;
		if (!TRUE) cout << "FALSE" << endl;
	}
}