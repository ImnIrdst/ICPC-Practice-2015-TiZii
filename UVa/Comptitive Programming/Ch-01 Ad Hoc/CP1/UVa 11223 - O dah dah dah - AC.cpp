#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

map<string, char> mp;

int main(){
	// Alpha
    mp[".-"] = 'A';			mp["-..."] = 'B';	mp["-.-."] = 'C'; 	mp["-.."] = 'D';
    mp["."] = 'E';			mp["..-."] = 'F'; 	mp["--."] = 'G'; 	mp["...."] = 'H';
    mp[".."] = 'I';			mp[".---"] = 'J'; 	mp["-.-"] = 'K'; 	mp[".-.."] = 'L';
    mp["--"] = 'M';			mp["-."] = 'N'; 	mp["---"] = 'O'; 	mp[".--."] = 'P';
    mp["--.-"] = 'Q';		mp[".-."] = 'R';	mp["..."] = 'S'; 	mp["-"] = 'T';
    mp["..-"] = 'U';		mp["...-"] = 'V';	mp[".--"] = 'W'; 	mp["-..-"] = 'X';
    mp["-.--"] = 'Y';		mp["--.."] = 'Z';
    mp["-----"] = '0'; 		mp[".----"] = '1'; mp["..---"] = '2';
    mp["...--"] = '3'; 		mp["....-"] = '4'; mp["....."] = '5';
    mp["-...."] = '6'; 		mp["--..."] = '7'; mp["---.."] = '8'; 
    mp["----."] = '9';
    mp[".-.-.-"] = '.';		mp["--..--"] = ','; mp["..--.."] = '?';
    mp[".----."] = '\'';	mp["-.-.--"] = '!'; mp["-..-."] = '/';
    mp["-.--."] = '(';		mp["-.--.-"] = ')'; mp[".-..."] = '&';
    mp["---..."] = ':'; 	mp["-.-.-."] = ';'; mp["-...-"] = '=';
    mp[".-.-."] = '+'; 		mp["-....-"] = '-'; mp["..--.-"] = '_';
    mp[".-..-."] = '\"'; 	mp[".--.-."] = '@'; mp[".--.-."] = '@';
	int cs=1; string str;
	int tc; cin >> tc; cin.ignore(); 
	while(tc--){getline(cin, str);
		cout << "Message #" << cs++ << endl;		
		for(int i=0 ; i<str.length() ;){
			string str2="";
			while(str[i]!=' ' && i<str.length() ) str2+=str[i++];
			cout << mp[str2];
			if(str[++i]==' ') cout << ' ', i++;
		}
		cout << endl;
		if(tc) cout << endl;
	}
}