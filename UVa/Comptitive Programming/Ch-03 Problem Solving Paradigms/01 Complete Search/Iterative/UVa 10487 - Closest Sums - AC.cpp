#include <iostream>
#include <cmath>

using namespace std;

const int Max = 1e3 + 10; int a[Max], n, cs=1;

int main(){
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++) cin >> a[i]; 
		cout << "Case " << cs++ << ":" << endl;

		int q;
		cin >> q;
		while(q--){
			int num; cin >> num;
			int MinDif=1e9, ans;
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<i ; j++){
					if(abs(a[i]+a[j]-num)<MinDif){
						MinDif=abs(a[i]+a[j]-num); ans=a[i]+a[j];
					}
				}
			}
			cout << "Closest sum to " << num << " is " << ans << "." << endl;
		}
		
	}
}