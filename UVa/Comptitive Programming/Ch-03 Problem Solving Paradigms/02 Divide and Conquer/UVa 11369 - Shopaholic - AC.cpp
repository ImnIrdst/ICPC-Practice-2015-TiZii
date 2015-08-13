#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int a[20000+10], n;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}

		int ans=0; sort(a,a+n,::greater<int>());
		for(int i=2 ; i<n ; i+=3){
			ans+=a[i];
		}
		cout << ans << endl;
	}
}