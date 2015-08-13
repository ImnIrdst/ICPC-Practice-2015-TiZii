#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Max = (1<<15) + 10;

int w[Max], wsum[Max];

int main(){
	int n;
	while(cin >> n){
		for(int i=0 ; i<(1<<n) ; i++){
			cin >> w[i];
		}
		memset(wsum, 0, sizeof wsum);
		for(int i=0 ; i<(1<<n) ; i++){
			for(int j=0 ; j<n ; j++){
				wsum[i]+=w[(i^(1<<j))];
			}
		}

		int ans=-1;
		for(int i=0 ; i<(1<<n) ; i++){
			for(int j=0 ; j<n ; j++){
				ans = max(ans, wsum[i]+wsum[(i^(1<<j))]);
			}
		}
		cout << ans << endl;
	}
}