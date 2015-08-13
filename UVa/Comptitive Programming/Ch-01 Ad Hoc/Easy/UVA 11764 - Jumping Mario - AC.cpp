#include <iostream>

using namespace std;

int main(){
	int tc, cs=1; cin >> tc;
	while(tc--){
		int n; cin >> n; 
		int a, b; cin >> a;
		int high = 0, low = 0;
		for(int i=0 ; i<n-1 ; i++){
			cin >> b; 
			if(a < b) high++;
			if(a > b) low++;
			a = b;
		}
		cout << "Case " << cs++ << ": ";// << endl; 
		cout << high << " " << low << endl;
	}
}