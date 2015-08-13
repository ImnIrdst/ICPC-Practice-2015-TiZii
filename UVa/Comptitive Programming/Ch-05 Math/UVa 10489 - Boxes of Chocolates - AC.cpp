#include <iostream>

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){ int ans=0;
		int n, b; cin >> n >> b; 
		for(int i=0 ; i<b ; i++){
			int k,choco=1; cin >> k;
			while(k--){
				int t; cin >> t; 
				choco*=t; choco%=n;
			}
			ans+=choco; ans%=n;
		}
		cout << ans << endl;
	}
}