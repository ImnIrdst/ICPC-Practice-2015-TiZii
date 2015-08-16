#include <iostream>

using namespace std;

int jose(int n, int k){
	if(n==1) return 0;
	return (jose(n-1,k)+k)%n;
}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while(tc--){
		int n, k; cin >> n >> k;

		cout << "Case " << cs++ << ": " << jose(n,k)+1 << endl;
	}
}