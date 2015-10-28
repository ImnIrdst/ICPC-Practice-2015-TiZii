#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int cs; cin >> cs;

		int a[12], n = 12;
		for (int i = 0; i < n; i++) cin >> a[i];

		int ans = 0;
		for (int i = 1; i < n - 1; i++){
			for (int j = i; j < n - 1; j++){
				int Min = 1e9;
				for (int k = i; k <= j; k++){
					Min = min(Min, a[k]);
				}
				if (Min > a[i - 1] && Min > a[j + 1]) ans++;
			}
		}

		cout << ans << endl;
	}
}