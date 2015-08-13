#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	while(cin >> str && str!="0"){
		int mod=0;
		for(int i=0, j=1 ; i<str.length() ; i++, j*=10, j%=11){

			mod+=j*(str[i]-'0'); mod%=11;
		}
		
		if(mod==0) cout << str << " is a multiple of 11." << endl;
		else	   cout << str << " is not a multiple of 11." << endl;
	}
}