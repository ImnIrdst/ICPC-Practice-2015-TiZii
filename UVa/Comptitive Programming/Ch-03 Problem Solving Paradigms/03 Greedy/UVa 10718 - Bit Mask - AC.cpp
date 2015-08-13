#include <iostream>

using namespace std;

void printbits(unsigned int n){
	for(int i=31 ; i>=0 ; i--){
		if(n & (1<<i)) cout << 1; else cout << 0;
	}cout << endl;
}


int main(){
	unsigned int N, L, U;
	while(cin >> N >> L >> U){
		unsigned int M = 0;
		for(int i=31 ; i>=0 ; i--){
			unsigned int Mask = (1u << i);
			if(!(N & Mask) && ((M|Mask) <= U)) 
				M |= Mask;
			if( (L & Mask) && (M      <  L))
				M |= Mask;
		}
		//printbits(N);
		//printbits(M);
		cout << M << endl;
	}
}