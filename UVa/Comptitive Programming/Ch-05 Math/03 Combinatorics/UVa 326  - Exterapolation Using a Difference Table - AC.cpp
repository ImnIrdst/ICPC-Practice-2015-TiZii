#include <iostream>

using namespace std;

int main(){
	int n, k, arr[150];
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++){
			cin >> arr[i];
		}cin >> k;

		for(int j=n-1 ; j>=0 ; j--){
			for(int i=0 ;  i<j  ; i++){
				arr[i] = arr[i+1] - arr[i];
			}
		}
		for(int j=0 ; j<k ; j++){
			for(int i=1 ; i<n ; i++){
				arr[i]+=arr[i-1];
			}
		}
		cout << "Term " << n+k << " of the sequence is " << arr[n-1] << endl;
	}
}