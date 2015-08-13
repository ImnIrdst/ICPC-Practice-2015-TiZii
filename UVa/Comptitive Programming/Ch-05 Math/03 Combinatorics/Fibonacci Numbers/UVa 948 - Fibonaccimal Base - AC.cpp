#include <iostream>
#include <string>

using namespace std;

typedef long long int64;

int64 fib[100], n;

int main(){
	fib[0]=0, fib[1]=1;
	for(int i=2 ; i<50 ; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	int tc; cin >> tc;
	while(tc--){ cin >> n; 
		int ii=0; while(fib[ii]<=n) ii++;
		
		cout << n << " = ";
		for(int i=ii-1 ; i>1 ; i--){
			if(fib[i]<=n) cout << '1', n-=fib[i];
			else cout << '0';
		}
		cout << " (fib)" << endl;
	}
}