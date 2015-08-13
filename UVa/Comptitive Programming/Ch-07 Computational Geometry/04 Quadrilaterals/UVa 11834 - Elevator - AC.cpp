#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

double L,C,R1,R2;

int main(){
	while(cin >> L >> C >> R1 >> R2 && (L||C||R1||R2)){
		int mn = min(L,C);
		if( mn < 2*R1 || mn < 2*R2){ cout << 'N' << endl; continue; }
		
		int l = L-(R1+R2), c = C-(R1+R2);
		if( l < 0 || c < 0 ){ cout << 'N' << endl; continue; }
		if( sqrt(l*l+c*c) >= R1+R2 ){ cout << 'S' << endl; continue; }
		
		cout << 'N' << endl;
	}
}