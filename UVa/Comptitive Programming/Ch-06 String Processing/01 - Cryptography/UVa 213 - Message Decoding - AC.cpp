#include <iostream>
#include <string>
#include <map>

using namespace std;

int pow2[11] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

string genSeq(int n, int len){
	string seq = "";
	if (!n) seq += "0";
	while (n){
		seq = char('0' + n % 2) + seq; n /= 2;
	}
	while (seq.length() != len) seq = "0" + seq;
	return seq;
}

int isAllOne(const string& str){
	for (int i = 0; i < str.length(); i++){
		if (str[i] == '0') return false;
	}
	return true;
}

int main(){
	string line;
	while (getline(cin, line)){
		map<string, char> mp;
		string seq = "0"; mp[seq] = line[0];

		int i = 0;
		for (int len = 1; len <= 7 && i<line.length(); len++){
			for (int j = 0; j < pow2[len] - 1 && i<line.length(); j++){
				mp[genSeq(j, len)] = line[i]; i++;
			}
		}
		string ans;
		char dig;
		while (true){
			int len = 0;
			cin >> dig; len = len * 2 + (dig - '0');
			cin >> dig; len = len * 2 + (dig - '0');
			cin >> dig; len = len * 2 + (dig - '0');
			if (len == 0) break;
			while (true){
				string seq;
				for (int i = 0; i < len; i++){
					cin >> dig; seq += dig;
				}
				if (isAllOne(seq)) break;
				ans+=mp[seq];
			}
		}
		cout << ans << endl;
		getline(cin, line);
	}
}