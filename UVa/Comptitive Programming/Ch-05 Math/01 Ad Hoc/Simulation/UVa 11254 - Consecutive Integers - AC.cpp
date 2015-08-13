#include <iostream>
#include <cmath>

using namespace std;

int main(){
	// Just Use Sum of Arithmetic Sequences (s = n/2 {2a+(n-1)*d) 
	// Here d is 1, we must find a , n;
	int s; while(cin >> s && s!=-1){
		int n=0 , a=0;
		for(n = (int)sqrt(2*s) ; n>0 ; n--){
			if( (2*s+n-n*n)%(2*n) == 0 ){ // if a is an integer
				a = (2*s+n-n*n)/(2*n); break;
			}
		}
		if(s==0) cout << s << " = " << 0 << " + ... + " << 0     << endl;
		if(s!=0) cout << s << " = " << a << " + ... + " << a+n-1 << endl;
	}
}