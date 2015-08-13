#include <iostream>

using namespace std;

typedef long long int64;

int main(){
	int64 tc; cin >> tc;
	while(tc--){
		int64 n, ans=0; cin >> n;
		int64 FarmSize, Animals, Friendly; 
		for(int i=0 ; i<n ; i++){
			cin >> FarmSize >> Animals >> Friendly;
			ans+=(FarmSize*Friendly);
		}
		cout << ans << endl;
	}
}
