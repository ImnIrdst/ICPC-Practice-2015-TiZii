#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long int64;

string IntToStr(int64 n){
	stringstream sstr; sstr << n;
	string str; sstr >> str; return str;
}

int64 StrToInt(string& str){
	stringstream sstr; sstr << str;
	int64 n; sstr >> n; return n;
}

int64 isPalindrome(string str){
	string rev = str; reverse(rev.begin(), rev.end()); 
	return str == rev;
}

int64 RevNum(int64 n){
	string rev = IntToStr(n); reverse(rev.begin(), rev.end()); 
	return StrToInt(rev);
}

int main(){
	int64 tc; cin >> tc;
	while(tc--){
		int64 n; cin >> n; int64 itrs=0;
		while(!isPalindrome(IntToStr(n))){
			n = n + RevNum(n); itrs++;
		}
		cout << itrs << " " << n << endl;
	}
}