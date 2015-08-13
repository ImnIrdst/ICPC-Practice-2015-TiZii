#include <iostream>
#include <cmath>

using namespace std;

typedef long long int64;

int64 a[100000+10], n;

int main(){
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		int64 ans=0;
		for(int i=0 ; i<n-1 ; i++){
			a[i+1] += a[i]; ans += (int64)abs(a[i]);
		}
		cout << ans << endl;
	}
}