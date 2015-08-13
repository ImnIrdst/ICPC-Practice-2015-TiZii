#include <iostream>
#include <functional>
#include <set>

using namespace std;

typedef long long int64;

int64 gcd(int64 a, int64 b){ return (b ? gcd(b,a%b) : a); }

int main(){
	int64 tc,cs=1,n; cin >> tc;
	while(tc--){
		cin >> n; n = n * (n-1);
		cout << "Case " << cs++ << ": ";
		if(gcd(n,4)==4) cout << n/gcd(n,4) << endl;
		else cout << n/gcd(n,4) << "/" << 4/gcd(n,4) << endl; 
	}
}