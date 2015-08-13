#include <iostream>

using namespace std;

typedef long long int64;

int main(){
	int n, cs=1;
	while( cin >> n && n){
		cout << "Case " << cs++ << ": " << n/2 << endl;
	}
}