#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <sstream>

using namespace std;

struct Time{
	int hh, mm; string str;
	Time(int hh = 0, int mm = 0)
		:hh(hh), mm(mm){ updateString(); }
	void inc(){
		mm++;
		if (mm == 60) mm = 0, hh++;
		if (hh >= 24) hh = 0;
		updateString();
	}

	bool isPalind(){
		string tmp = str;
		tmp.erase(2, 1); // remove ':'

		string org = ""; bool flag=1;
		for (int i = 0; i < tmp.length(); i++){
			if (tmp[i] == '0' && flag) continue; 
			else flag = 0, org += tmp[i];
		}

		string rev = org; 
		reverse(rev.begin(), rev.end());
		return rev == org;
	}

	void updateString(){
		stringstream sstr; str.clear();
		sstr << setw(2) << setfill('0') << hh;
		sstr << ":";
		sstr << setw(2) << setfill('0') << mm;
		sstr >> str;
	}
};

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int hh, mm; char c;
		cin >> hh >> c >> mm;

		Time tm(hh, mm); tm.inc();
		while (!tm.isPalind()) 
			tm.inc();

		cout << tm.str << endl;
	}

}