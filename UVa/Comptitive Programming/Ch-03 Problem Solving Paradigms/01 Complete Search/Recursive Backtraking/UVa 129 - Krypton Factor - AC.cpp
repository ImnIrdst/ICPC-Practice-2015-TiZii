
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n, l, cur; string ans;
char str[80 + 10] = { 0 };

bool backtrack(int c){
	// check if we found nth number
	if (cur == n) ans = str; cur++;
	// add one letter to the end of current string 
	for (int i = 0; i < l; i++){
		str[c] = 'A' + i;
		// check if it has adjoining repetition
		bool ok = true;
		int len = strlen(str);
		for (int j = 1; j * 2 <= len; j++){
			bool repFound = true;
			for (int k = 0; k < j; k++){
				if (str[c - k ] != str[c - k - j]){
					repFound = false; break;
				}
			}
			if (repFound){
				ok = false; break;
			}
		}
		if (ok) if (!backtrack(c + 1)) return false;
		if (ans[0] != '#') break;
	}
	str[c] = '\0';
	return true;
}

int main(){
	while (cin >> n >> l && (n||l)){
		memset(str, 0, sizeof str);
		ans = "#"; cur = 0; backtrack(0); 
		for (int i = 0; i < ans.length(); i++){
			if (i != 0 && i % 64 == 0) cout << endl;
			else
			if (i != 0 && i % 04 == 0) cout << " " ;
			cout << ans[i];
		}
		cout << endl << ans.length() << endl;
	}
}