#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> mp;

string getInQoute(const string& str) {
	bool inqoute = false; string ret = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '\"') {
			inqoute = 1 - inqoute;
		}
		if (inqoute) ret += str[i];
	}
	return ret + "\"";
}

struct pis { // pair id , string
	string title, author; bool returned;
	pis(const string& name = "") {
		title = getInQoute(name);
		author = name.substr(title.length() + 4);
		mp[title] = author; returned = false;
	}
	pis(const string& author, const string& title)
		:title(title), author(author), returned(false) {}
	bool operator<(const pis& op) const {
		return (op.author != author ? author < op.author : title < op.title);
	}
};



int main() {
	// get input pair id , string
	set<pis> books;
	set<pis>::iterator it;
	string line; int id = 0;
	map<string, bool> returned;
	vector<pis> input_order;
	while (getline(cin, line) && line != "END") {
		pis book(line);
		books.insert(pis(line));
		input_order.push_back(book);
		returned[book.title] = false;
	}

	string cmd;
	sort(input_order.begin(), input_order.end());
	while (cin >> cmd && cmd != "END") {
		if (cmd[0] == 'B') {
			getline(cin, line); line = getInQoute(line);
			it = books.find(pis(mp[line], line));
			if (it != books.end()) books.erase(it);
		}
		if (cmd[0] == 'R') {
			getline(cin, line); line = getInQoute(line);
			returned[line] = true;
		}
		if (cmd[0] == 'S') {
		for (int i = 0; i < input_order.size(); i++) {
				string title = input_order[i].title;
				if (returned[title] == true) {
					returned[title] = false;
					books.insert(pis(mp[title], title));
					it = books.find(pis(mp[title], title));
					if (it == books.begin()) {
						cout << "Put " << title << " first" << endl;
					}
					else {
						it--;
						cout << "Put " << title << " after " << it->title << endl;
					}
				}
			}
			cout << "END" << endl;
		}
	}

}