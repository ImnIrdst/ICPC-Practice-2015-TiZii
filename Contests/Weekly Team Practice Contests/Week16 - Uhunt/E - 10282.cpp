#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

map<string, string> dict;

int main()
{

	string str;
	getline(cin, str);
	while (!str.empty()) {
		stringstream sstr(str);
		string s1, s2;
		sstr >> s1 >> s2;
		dict.insert(pair<string,string>(s2,s1));
		getline(cin, str);
	}
	while (cin >> str) {
		map<string, string>::iterator it;
		int ans = dict.count(str);
		if (ans) {
			cout << dict[str] << endl;
		}
		else {
			cout << "eh" << endl;
		}
	}
	return 0;
}