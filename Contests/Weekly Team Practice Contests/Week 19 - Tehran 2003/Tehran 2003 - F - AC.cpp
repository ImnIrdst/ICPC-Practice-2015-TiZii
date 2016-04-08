#include<iostream>
#include<algorithm>
#include<functional>
#include<sstream>
#include<string>
#include<string.h>
#include<cctype>
#include<cmath>
using namespace std;

typedef pair<int, int> PII;
#define		EPS		1e-8

int str2int(const string& s){

	int n;
	stringstream sstr(s);
	sstr >> n;
	return n;
}

PII Pars(const string& s){
	PII ans(0, 0);//x - const
	int sign = 1;
	for (int i = 0; i < s.size(); ++i){
		char str_num[30];
		int top = 0;
		if (s[i] == ' '){  continue; } //skip blanks
		while (isdigit(s[i])){ //extract numbers
			str_num[top++] = s[i++];
		}
		str_num[top] = 0;
		int number = top ? str2int(str_num) : 0;
		if (s[i] == 'x'){
			ans.first += sign * (number ? number : 1);
		}
		else{
			ans.second += sign * number;
			sign = (s[i] == '+') ? 1 : -1; // update sign
		}
	}
	return ans;
}

int main()
{
	int tc;
	string tmp;
	getline(cin, tmp);
	tc = str2int(tmp);
	while (tc--){
		string line;
		getline(cin, line);
		int eqPos = 0;
		for (int i = 0; i < line.size(); ++i){
			if (line[i] == '='){
				eqPos = i;
				break;
			}
		}
		PII left, right;
		left = Pars(line.substr(0, eqPos));
		right = Pars(line.substr(eqPos + 1 , line.size() - eqPos));
		int num = right.second - left.second;
		int denom = left.first - right.first;
		if (denom == 0 && num != 0){
			cout << "IMPOSSIBLE" << endl;
		}
		else if (denom == 0 && num == 0){
			cout << "IDENTITY" << endl;
		}
		else{
			int ans = (int)(floor(num / (float)denom));
			if (ans){
				cout << ans << endl;
			}
			else
				cout << "0" << endl;

		}
		
	}
	return 0;
}