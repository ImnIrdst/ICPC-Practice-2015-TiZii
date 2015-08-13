#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int log2(int n){ int cnt=0; while(n/=2) cnt++; return cnt; }

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n,b1,b2; cin >> n >> b1 >> b2;
		int greater=max(log2(b1),log2(b2));
		cout << (1<<n)-(1<<(n-greater))+1 << endl;
	}
}