#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		for(int i=0 ; i<str.length() ; i++) 
			if(!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')))
				str[i]=' ';
		stringstream sstr(str);

		int ans=0;
		while(sstr >> str) ans++;
		cout << ans << endl;
	}
}
