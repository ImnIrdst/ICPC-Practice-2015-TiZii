#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int64;

int64 tobase10(string num, int64 b, int64 m){
	int64 ret=0;
	for(int64 i=num.length()-1, j=1 ; i>=0 ; i--, j*=b, j%=m){
		ret+=(num[i]-'0')*j; ret%=m;
	}
	return ret;
}

string tobase(int64 num, int64 b){
	if(num==0) return "0";
	string ret="";
	while(num){
		ret+=('0'+num%b); num/=b;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	string ps, ms; int64 p,b,m;
	while(cin >> b && b){
		cin >> ps >> ms; 
		m = tobase10(ms, b, 1e18);
		p = tobase10(ps, b, m);
		cout << tobase(p, b) << endl;
	}
}