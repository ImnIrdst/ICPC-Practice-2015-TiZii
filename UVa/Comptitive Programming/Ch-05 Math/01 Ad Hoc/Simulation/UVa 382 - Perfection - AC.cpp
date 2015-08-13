#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(){
	cout << "PERFECTION OUTPUT" << endl;
	int n; while(cin >> n && n){
		int sum = 1 ;
		for(int i=2 ; i*i<=n ; i++){
			if( n%i == 0 ) sum += i + n/i;
			//if( i*i == n ) sum -= i;
		}
		if( n == 1 ) sum -= 1e9;
		cout << setw(5) << n << "  ";
		if( sum <  n ) cout << "DEFICIENT" << endl;
		if( sum >  n ) cout << "ABUNDANT"  << endl;
		if( sum == n ) cout << "PERFECT"   << endl; 
	}
	cout << "END OF OUTPUT" << endl;
}