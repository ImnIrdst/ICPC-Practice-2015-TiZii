#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int tim[256 + 10];
	int grp[256 + 10];
	tim['A'] = 1; grp['A'] = 1;
	tim['B'] = 2; grp['B'] = 1;
	tim['C'] = 3; grp['C'] = 1;
	
	tim['D'] = 1; grp['D'] = 2;
	tim['E'] = 2; grp['E'] = 2;
	tim['F'] = 3; grp['F'] = 2;

	tim['G'] = 1; grp['G'] = 3;
	tim['H'] = 2; grp['H'] = 3;
	tim['I'] = 3; grp['I'] = 3;

	tim['J'] = 1; grp['J'] = 4;
	tim['K'] = 2; grp['K'] = 4;
	tim['L'] = 3; grp['L'] = 4;

	tim['M'] = 1; grp['M'] = 5;
	tim['N'] = 2; grp['N'] = 5;
	tim['O'] = 3; grp['O'] = 5;

	tim['P'] = 1; grp['P'] = 6;
	tim['Q'] = 2; grp['Q'] = 6;
	tim['R'] = 3; grp['R'] = 6;
	tim['S'] = 4; grp['S'] = 6;

	tim['T'] = 1; grp['T'] = 7;
	tim['U'] = 2; grp['U'] = 7;
	tim['V'] = 3; grp['V'] = 7;

	tim['W'] = 1; grp['W'] = 8;
	tim['X'] = 2; grp['X'] = 8;
	tim['Y'] = 3; grp['Y'] = 8;
	tim['Z'] = 4; grp['Z'] = 8;

	tim[' '] = 1; grp[' '] = 0;

	int tc;
	cin >> tc;
	while (tc--){
		int pres; cin >> pres;
		int wait; cin >> wait;
		int ans = 0; 
		string str; getline(cin, str); getline(cin, str);
		for (int i = 0; i < str.length(); i++){
			ans += tim[str[i]]*pres;
			if (i>0 && grp[str[i]] == grp[str[i - 1]] && str[i]!=' ') ans += wait;
		}
		cout << ans << endl;
	}
}