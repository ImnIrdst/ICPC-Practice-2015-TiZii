#include <iostream>

using namespace std;

typedef long long int64;

int main(){
	int64 cs=1, n;
	while(cin >> n && n){
		int64 lo=0, hi=1e9, mid;
		while(lo<hi){
			mid = (lo+hi)/2;
			if((mid*(mid-3))/2 >= n) hi=mid; else lo=mid+1;
		}
		cout << "Case " << cs++ << ": " << hi << endl;
	}
}