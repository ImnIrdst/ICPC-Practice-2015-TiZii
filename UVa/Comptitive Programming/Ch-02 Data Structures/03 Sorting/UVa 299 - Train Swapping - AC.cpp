#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long

using namespace std;

int ans,n; int arr[100];

int main(){
	int tc; cin >> tc;
	while(tc--){
		ans=0; cin >> n;
		for(int i=0 ; i<n ; i++){
			cin >> arr[i];
		}
		for(int i = 0; i < n - 1; i++)
			for(int j = i+1; j < n; j++)
				if(arr[i] > arr[j])
					ans++;
		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}
	return 0;
}