#include <iostream>

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
	int cs=1;
	cin >> tc;
	while(tc--){
		int64 n, k, m; cin >> n >> k >> m;
		
		int64 sum=0, tmp;
		for(int i=0 ; i<n ; i++){
			cin >> tmp; sum+=tmp; sum%=m;
		}
		cout << "Case " << cs++ << ": " << (PowMod(n,k-1,m)*sum*(k%m))%m << endl;
	}
}