#include <iostream>
#include <algorithm>

using namespace std;

double n,h,w;

int main(){
	while(cin >> n && n){
		double MaxSide=-1, MaxIdx;
		for(int i=1 ; i<=n ; i++){
			cin >> h >> w;
			if( min(h,w/4)   > MaxSide) MaxIdx = i, MaxSide = min(h,w/4);
			if( min(w,h/4)   > MaxSide) MaxIdx = i, MaxSide = min(w,h/4);
			if( min(h/2,w/2) > MaxSide) MaxIdx = i, MaxSide = min(h/2,w/2);
		}
		cout << MaxIdx << endl;
	}
}