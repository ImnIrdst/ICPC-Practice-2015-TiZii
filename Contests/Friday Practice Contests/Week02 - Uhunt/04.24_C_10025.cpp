#include <iostream>
#include <cmath>

using namespace std;

typedef long long int64;

int64 Abs(int64 n){return (n<0 ? -n : n);}

int main(){
	int64 tc, n; cin >> tc;
	while(tc--){ cin >> n;
		int64 k, lo=0, hi=1e9, ans, sum;
		while(lo<hi){
			k = (lo+hi)/2; sum = (k*(k+1))/2; //cout << lo << " " << hi << " " << (k*(k-1))/2 << endl;
			if(sum>=Abs(n)) hi=k, ans=sum; else lo = k+1;
		}
		while(ans%2!=Abs(n)%2) hi++, ans = (hi*(hi+1))/2;
		hi = ( n? hi : 3); cout << hi << endl;
		if(tc) cout << endl;
	}
}