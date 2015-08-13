#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,nn,m,mm,q;

string check(int k){
	if(n%k==2 && m%k==0) return "YES";
	if(n%k==0 && m%k==2) return "YES";

	if((n-m)%(m-1)==0 && (m-1)%k==0) return "YES";
	return "NO";
}

int main(){
	
	cin >> nn >> mm >> q;
	n=max(mm,nn), m=min(mm,nn);
	while(q--){
		int k; cin >> k;
		cout << check(k) << endl;
	}
}