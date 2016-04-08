#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct phone{
	string code, num;
	phone(string code = "", string num = "")
		:code(code), num(num){}
};

struct changeOfCode{
	int year; string code;
	changeOfCode(int year = 0, const string& code = "")
		:code(code), year(year){}
	bool operator<(const changeOfCode& op) const{
		return year < op.year;
	}
	bool operator!=(const changeOfCode& op) const{
		return make_pair(year, code) != make_pair(op.year, op.code);
	}
};

struct change{
	string city; int year, type, val;  string code;
	change(int year = 0, const string& city = "", int type = 0, int val = 0, const string& code="")
		:year(year), city(city), type(type), val(val), code(code){}
	bool operator<(const change& op) const{
		return year < op.year;
	}
};

map<string, set<changeOfCode> > mp;

string getCityFromCode(const string& code,  int year){
	set<changeOfCode>::iterator stIt;
	map<string, set<changeOfCode> >::iterator mpIt;
	for (mpIt = mp.begin(); mpIt != mp.end(); mpIt++){
		set<changeOfCode>& st = mpIt->second;
		stIt = st.lower_bound(changeOfCode(year, code)); 
		if(stIt == st.end() || *stIt != changeOfCode(year, code)) stIt--;
		if (stIt->code == code) return mpIt->first;
	}
	return "";
}

int main(){
	int n; cin >> n;

	string city, val;
	vector<change> changes;
	for (int i = 0; i < n; i++){
		cin >> val >> city; 
		mp[city].insert(changeOfCode(-1, val));
	}

	int m; cin >> m;

	change ch;
	for (int i = 0; i < m; i++){
		cin >> ch.year >> ch.type >> ch.city;
		if(ch.type != 3) cin >> ch.val;
		if (ch.type == 3) cin >> ch.code;
		changes.push_back(ch);

		if (ch.type == 3){
			mp[ch.city].insert(changeOfCode(ch.year, ch.code));
		}
	}
	sort(changes.begin(), changes.end());

	while (true){
		int year0; cin >> year0;
		int year1; cin >> year1;
		phone p;
		string num, city; cin >> num;
		if (year0 + year1 == 0 && num == "0") break;
		for (int i = 1; i <= num.length(); i++){
			city = getCityFromCode(num.substr(0, i), year0);
			if (city.length()){
				p = phone(num.substr(0, i), num.substr(i)); break;
			}
		}

		for (int i = 0; i < changes.size(); i++){
			change deb = changes[i];
			if (year0 >= changes[i].year) continue;
			if (city  != changes[i].city) continue;
			if (year1 < changes[i].year) continue;
			if (changes[i].type == 3){
				p.code = changes[i].code;
			}
			if (changes[i].type == 1){
				char rep[3] = { p.num[changes[i].val - 1], p.num[changes[i].val - 1], '\0' };
				p.num.replace(changes[i].val-1, 1, rep);
			}
			if (changes[i].type == 2){
				swap(p.num[changes[i].val], p.num[changes[i].val-1]);
			}
		}
		cout << p.code << p.num << endl;
	}
}