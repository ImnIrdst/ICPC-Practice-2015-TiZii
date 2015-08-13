#include <iostream>
#include <cmath>

using namespace std;

typedef long long int64;

int64 gcd(int64 a, int64 b){
	return (b==0 ? a : gcd(b, a%b));
}

int64 x, y, d;
void extendedEuclid(int64 a, int64 b){
	if(b==0){ x=1, y=0, d=a; return; }
	extendedEuclid(b, a%b);
	int64 x1=y, y1=x-(a/b)*y;
	x = x1, y = y1;
}

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		int64 xx, kk; cin >> xx >> kk;
		extendedEuclid(floor(xx/(double)kk), ceil(xx/(double)kk));
		int64 g = gcd(floor(xx/kk), ceil(xx/kk));
		cout << x*(xx/d) << " " << y*(xx/d) << endl;
	}
}