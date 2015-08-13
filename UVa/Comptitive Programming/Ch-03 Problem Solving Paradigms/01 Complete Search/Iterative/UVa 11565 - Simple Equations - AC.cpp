#include <iostream>

using namespace std;

typedef long long int64;

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		bool found=0;
		int64 A, B, C; cin >> A >> B >> C;
		for(int x=-110 ; x<=110 && !found ; x++){
			for(int y=-110 ; y<=110  && !found ; y++){
				int z = A-x-y;
				if( x*y*z == B && x*x+y*y+z*z == C && x<y && y<z){
					cout << x <<" " << y << " " << z << endl; found=1;
				}
			}
		}
		if(!found) cout << "No solution." << endl;
	}
}