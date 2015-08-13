#include <iostream>

using namespace std;

const int Max = 1e5+10;

int r[Max], n;

int simulate(int k){ int i=0;
	for(i=1 ; i<n && k>0 ; i++){
		if(r[i]-r[i-1] >k){i--; break;}
		if(r[i]-r[i-1]==k) k--;
	}
	return i==n;
}

int main(){
	int tc; 
	int cs=1;
	cin >> tc;
	while(tc--){
		cin >> n; n++; r[0]=0;
		for(int i=1 ; i<n ; i++){
			cin >> r[i];
		}
		int lo=0, hi=1e9, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			if(simulate(mid)) hi=mid; else lo=mid+1;
		}
		cout << "Case " << cs++ << ": " << hi << endl;
	}
}