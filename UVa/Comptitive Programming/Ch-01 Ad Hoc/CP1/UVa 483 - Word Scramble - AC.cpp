#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string str;
	while(getline(cin, str)){
		for(int i=0 ; i<str.length() ; i++){
			if(str[i]==' ') cout << ' ';
			else{
				string str2="";
				for(i=i ; i<str.length() && str[i]!=' ' ; i++) str2+=str[i];
				for(int j=str2.length()-1 ; j>=0 ; j--) cout << str2[j];
				if(i<str.length() && str[i]==' ') cout << ' ';
			}
		}
		cout << endl;
	}
}