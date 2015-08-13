#include <iostream>

using namespace std;

typedef long long int64;

int64 gcd(int64 a, int64 b){
	return (b ? gcd(b,a%b) : a);
}

int main(){
	int64 n, k;
	while(cin >> n >> k && (n||k)){
		int64 ans = 1;
		if(k>n/2) k = n-k;
		for(int64 i=0 ; i<k ; i++){
			ans *= (n-i);
			if(gcd(i+1,ans)==i+1) ans/=(i+1);
		}
		cout << ans << endl;
	}
}