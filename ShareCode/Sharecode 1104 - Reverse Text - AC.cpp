#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int tc; cin >> tc; cin.ignore();
	while(tc--){ 
		string str; getline(cin,str);
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
}