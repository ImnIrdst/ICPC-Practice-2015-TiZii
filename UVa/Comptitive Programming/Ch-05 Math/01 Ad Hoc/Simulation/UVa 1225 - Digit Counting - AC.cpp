#include <iostream>
#include <cstring>

using namespace std;

int digits[10];

void ParseDigits(int n){
	if( n == 0 ) digits[0]++;
	while( n ){
		digits[n%10]++; n/=10;
	}
}

int main(){
	int tc; 
	cin >> tc;
	while( tc-- ){
		memset(digits, 0, sizeof digits);
		
		int n; cin >> n;
		for(int i=1 ; i<=n ; i++) 
			ParseDigits(i);

		cout << digits[0];
		for(int i=1 ; i<=9 ; i++) 
			cout << " " << digits[i]; 
		cout << endl;
	}
}