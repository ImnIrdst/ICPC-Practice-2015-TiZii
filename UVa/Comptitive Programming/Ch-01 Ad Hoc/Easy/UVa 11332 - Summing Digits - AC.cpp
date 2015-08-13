#include <iostream>

using namespace std;

int f(int n){
	int sum=0;
	for(int t=n ; t ; t/=10){
		sum+=(t%10);
	}
	return sum;
}

int main(){
	int n;
	while(cin >> n && n){
		int prev=-1;
		while(n!=prev){
			prev = n; n = f(n);
		}
		cout << n << endl;
	}
}