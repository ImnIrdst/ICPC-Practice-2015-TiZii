#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <bitset>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int n; 
	while(cin >> n){
		bitset<32> a(n),b; int ans=0;
		for(int i=3 ; i>=0 ; i--){
			for(int j=0; j<8 ; j++){
				b[8*i+j]=a[(3-i)*8+j];	
			}
		}
		for(int i=0 ; i<32 ; i++) if(b[i]) ans+=(1<<i);
		cout << n << " converts to " << ans << endl;
	}
	return 0;
}