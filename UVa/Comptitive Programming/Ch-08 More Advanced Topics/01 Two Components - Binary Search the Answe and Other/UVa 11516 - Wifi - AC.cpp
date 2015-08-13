#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1e5 + 10;

int home[MAX], n, m;

int valid(int dist, int mm){
	int p = -1e9;
	for(int i=0 ; i<n ; i++){
		if(abs(home[i]-p) <= dist) continue;
		else mm--, p = home[i]+dist;
	}
	return (mm >= 0);
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){ cin >> m >> n;
		for(int i=0 ; i<n ; i++){
			cin >> home[i]; home[i]*=10;
		}
		sort(home, home+n);

		int mid;
		int lo=0, hi=1e9;
		while( lo < hi ){
			mid = (lo+hi)/2;
			if(valid(mid,m)) hi=mid; else lo=mid+1;
		}
		cout << hi/10 << "." << hi%10 << endl;
	}
}