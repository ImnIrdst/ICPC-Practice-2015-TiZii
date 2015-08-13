#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int toBase(string num, int base){ // Number, Base
	int ret = 0;
	for(int i=num.length()-1 , b = 1 ; i>=0 ; i--, b*=base){
		ret += (num[i]-'0')*b;
	}
	return ret;
}

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		string M; cin >> M;
		
		int b1 = 0, MD = toBase(M,10);
		for (int i = 0 ; i<32 ; i++) {
			if(MD & (1<<i)) b1++;
		}

		int b2 = 0, MH = toBase(M,16);
		for (int i = 0 ; i<32 ; i++) {
			if(MH & (1<<i)) b2++;
		}
		cout << b1 << " " << b2 << endl;
	}
}