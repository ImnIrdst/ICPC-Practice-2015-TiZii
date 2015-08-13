#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long int64;

vector<int64> arr;

int main(){
	for(int64 i=1 ; i<=(1e12) ; i*=2){
		for(int64 j=1 ; j<=(1e12) ; j*=3){
			if(i*j>1e12) break;
			arr.push_back(i*j);
		}
	}
	sort(arr.begin(), arr.end());
	int64 m, n;
	while(cin >> m && m){
		for(int i=0 ; i<arr.size() ; i++){
			if(arr[i]>=m){
				n=arr[i]; break;
			}
		}
		cout << n << endl;
	}
}