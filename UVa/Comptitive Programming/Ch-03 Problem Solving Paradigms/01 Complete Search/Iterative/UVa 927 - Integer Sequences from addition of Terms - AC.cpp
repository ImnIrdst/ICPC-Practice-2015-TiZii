#include <iostream>

using namespace std;

typedef long long int64;

int64 c[20+10], d, k, deg;

int64 an(int64 n){
	int64 ret=0;
	for(int64 i=0, p=1 ; i<deg+1 ; i++, p*=n){
		ret += p*c[i];
	}
	return ret;
}

int main(){
	int tc; 
	cin >> tc;
	while(tc--){
		cin >> deg;
		for(int i=0 ; i<deg+1 ; i++) cin >> c[i];
		cin >> d >> k;
		
		int64 occ=0, n=1; 
		while(occ+d*n < k) 
			occ+=d*n, n++;
		//cout << "#" << " " ; // DEB
		cout << an(n) << endl;
	}
}