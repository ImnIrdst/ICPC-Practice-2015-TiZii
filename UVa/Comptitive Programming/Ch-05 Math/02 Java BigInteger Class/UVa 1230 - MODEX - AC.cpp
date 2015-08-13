#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;

int64 Square(int64 x){ return x*x; }

int64 PowMod(int64 b, int64 p, int64 m){
	if(p   ==  0) return 1;
	if(p%2 ==  0) return Square(PowMod(b,p/2,m))%m;
	if(p%2 !=  0) return (((b%m)*PowMod(b,p-1,m))%m)%m;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int x, y, n;
		cin >> x >> y >> n;
		cout << PowMod(x, y, n) << endl;
	}
}