#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
	string str;
	while(getline(cin, str) && str!="DONE"){
		string st2 = "";
		for(int i=0 ; i<str.length() ; i++){
			if(isalpha(str[i])) st2+=tolower(str[i]);
		}
		string rev = st2; 
		reverse(rev.begin(), rev.end());

		if(st2 == rev)
			cout << "You won't be eaten!" << endl;
		else
			cout << "Uh oh.." << endl;
	}
}