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

int a[100000],n=1;

int main(){
	while(cin >> a[n++]){
		sort(a,a+n); n--;
		if(n%2){
			cout << a[n/2+1] << endl;
		}
		else{
			cout << (a[n/2]+a[n/2+1])/2 << endl;
		}
		n++;
	}
	return 0;
}