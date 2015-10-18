#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned long long int64;

char str[101]; int n;

int64 toBase10(int64 base){
	int64 ret = 0;
	for (int i = 0; i < n; i++){
		ret *= base; ret += int64(str[i] - '0');
	}
	return ret;
}

int main(){
	
	while (cin >> str && strcmp(str,"0")){
		n = strlen(str);

		int64 b = 1;
		for (int i = 0; i < n; i++){
			if (str[i] - '0' > b) b = str[i] - '0';
		}

		int64 ans = 0, toB, sq;
		for (b  = b + 1; b <= 100; b++){
			toB = toBase10(b);
			sq  = sqrt(toB);
			if (sq*sq == toB){
				ans = b; break;
			}
		}
		cout << ans << endl;
	}
}