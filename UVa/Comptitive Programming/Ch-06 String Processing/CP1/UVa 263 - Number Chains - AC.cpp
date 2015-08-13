#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int strtoint(string& str){
	stringstream sstr(str);
	int n; sstr >> n;
	return n;
}

string inttostr(int& n){
	stringstream sstr; sstr << n;
	string str; sstr >> str;
	return str;
}

int main(){
	string str;
	while(cin >> str && str[0]!='0'){
		cout << "Original number was " << strtoint(str) << endl;

		set<int> st; int num = strtoint(str), len=0;
		while(!st.count(num)){
			st.insert(num);
			string str1 = str, str2 = str;
			sort(str1.begin(), str1.end(), ::less<char>());
			sort(str2.begin(), str2.end(), ::greater<char>());
			num = strtoint(str2)-strtoint(str1);
			str = inttostr(num); len++;
			cout << strtoint(str2) << " - " << strtoint(str1) << " = " << num << endl;
		}
		cout << "Chain length " << len << endl << endl;
	}
}