#include <iostream>
#include <bitset>
#include <string>

using namespace std;

typedef long long int64;

int main(){
	int n;
	while(cin >> n && n){
		int64 a=0, b=0;
		for(int i=0, j=0 ; i<32 ; i++){
			if(n&(1<<i)){
				j++; if(j%2) a|=(1<<i); else b|=(1<<i);
			}
		}
		cout << a << " " << b << endl;
	}
}