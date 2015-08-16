// Josephus with k==2
#include <iostream>

using namespace std;

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while(tc--){
		int n; 
		cin >> n;
		
		int itrs=0; 
		while(true){
			int msb=0;
			for(int i=0 ; i<32 ; i++){
				if(n & (1<<i)) msb = i;
			}
			if( n == (n-(1<<msb))*2+1) break;
			else n = (n-(1<<msb))*2+1;
			itrs++;
		}

		cout << "Case " << cs++ << ": " << itrs << " " << n << endl;
	}
}