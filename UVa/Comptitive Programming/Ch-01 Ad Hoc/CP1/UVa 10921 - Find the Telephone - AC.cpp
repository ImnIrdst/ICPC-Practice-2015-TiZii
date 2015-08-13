#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char charCode(char c){
	if( 'A'<= c && c<='C') return '2';
	if( 'D'<= c && c<='F') return '3';
	if( 'G'<= c && c<='I') return '4';
	if( 'J'<= c && c<='L') return '5';
	if( 'M'<= c && c<='O') return '6';
	if( 'P'<= c && c<='S') return '7';
	if( 'T'<= c && c<='V') return '8';
	if( 'W'<= c && c<='Z') return '9';
	return c;
}

int main(){
	string str;
	while(getline(cin, str)){
		for(int i=0 ; i<str.length() ; i++){
			cout << charCode(str[i]);
		}
		cout << endl;
	}
}