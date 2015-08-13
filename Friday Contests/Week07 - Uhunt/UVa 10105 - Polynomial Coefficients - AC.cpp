#include <iostream>

using namespace std;

typedef long long int64;


int main(){
	int64 k, n, fact[14]={1};
	for(int i=1 ; i<=13 ; i++){
		fact[i] = fact[i-1]*i;
	}
	while(cin >> n >> k){
		int64 ans = fact[n], j;
		for(int i=0 ; i<k ; i++){
			cin >> j; ans /= fact[j];
		}
		cout << ans << endl;
	}

}