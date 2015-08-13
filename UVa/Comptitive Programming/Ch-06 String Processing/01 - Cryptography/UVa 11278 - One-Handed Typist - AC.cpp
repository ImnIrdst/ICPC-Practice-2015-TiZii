#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	string mp1="1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	     mp1 +="!@#$%^&*()_+QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?";
	string mp2="123qjlmfp/[]456.orsuyb;=789aehtdck-0zx,inwvg'";
	     mp2 +="!@#QJLMFP?{}$%^>ORSUYB:+&*(AEHTDCK_)ZX<INWVG\"";
	map<char,char> mp;
	for(int i=0 ; i<mp1.size() ; i++){
		mp[mp1[i]]=mp2[i];
	}
	char c;
	while(c=cin.get()){
		if(cin.eof()) break;
		if(mp.count(c)) cout << mp[c];
		else            cout << c;
	}
}