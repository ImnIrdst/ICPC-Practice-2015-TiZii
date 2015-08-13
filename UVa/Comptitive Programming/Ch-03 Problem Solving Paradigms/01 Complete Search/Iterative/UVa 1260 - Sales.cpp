#include <iostream>

using namespace std;

const int Max = 1e3 + 10; int a[Max];

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, ans = 0; 
		cin >> n; cin >> a[0];
		for(int i=1 ; i<n ; i++){
			cin >> a[i]; int cnt=0;
			for(int j=0 ; j<i ; j++){
				if(a[j]<=a[i]) cnt++;
			}
			ans += cnt;
		}
		cout << ans << endl;
	}
}