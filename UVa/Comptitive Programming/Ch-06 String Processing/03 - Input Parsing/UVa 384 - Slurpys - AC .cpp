#include <iostream>
#include <string>

using namespace std;

bool isSlump(const string& str){
	if (str.length() < 3) return false;
	if ((str[0] == 'D' || str[0] == 'E') && str[1] == 'F'){
		for (int i = 1; i < str.length(); i++){
			if (i == str.length() - 1) return str[i] == 'G';
			if (str[i] != 'F') return isSlump(str.substr(i));
		}
	}
	return false;
}

bool isSlimp(const string& str){
	if (str.length() < 2 || str[0] != 'A') return false;
	if (str.length() == 2 && str == "AH") return true;
	if (str.length() == 2 && str != "AH") return false;
	if (str[str.length() - 1] != 'C') return false;
	if (str[1] == 'B') return isSlimp(str.substr(2, str.length() - 3));
	return isSlump(str.substr(1, str.length() - 2));
}

bool isSlurpy(const string& str){
	for (int i = 2; i <= str.length() - 3; i++){
		if (isSlimp(str.substr(0, i)) && isSlump(str.substr(i, str.length() - i))) return true;
	}
	return false;
}

int main(){
	cout << "SLURPYS OUTPUT" << endl;
	int tc;
	cin >> tc;
	while (tc--){
		string inp; cin >> inp;
		if (isSlurpy(inp)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	cout << "END OF OUTPUT" << endl;
}