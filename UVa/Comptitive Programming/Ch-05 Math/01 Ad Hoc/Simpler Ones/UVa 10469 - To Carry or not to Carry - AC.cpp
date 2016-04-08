#include <iostream>

using namespace std;

int main(){
	unsigned int n, m;
	while (cin >> n >> m){
		unsigned int ans = n^m; cout << ans << endl;
	}
}