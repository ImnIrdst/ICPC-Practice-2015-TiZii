#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#define pi (2*acos(0))
#define toRad(x) (x*pi/180)

using namespace std;

int main(){
	int tc, a[4]; cin >> tc;
	while(tc--){

		for(int i=0 ; i<4 ; i++) 
			cin >> a[i];
		sort(a, a+4);
		
		int IsSquare = (a[0]==a[1] && a[1]==a[2] && a[2]==a[3]);
		if( IsSquare ) {cout << "square" << endl;     continue;}
		int IsRect   = (a[0]==a[1] && a[2]==a[3]);
		if( IsRect   ) {cout << "rectangle" << endl;  continue;}
		int IsQuad   = (a[3] < a[0]+a[1]+a[2]);
		if( IsQuad   ) {cout << "quadrangle" << endl; continue;}
		cout << "banana" << endl;
		
		
	}
}