#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int c[100000+10];

int main(){
	int n, k;
	while(cin >> n >> k && (n!=-1 || k!=-1)){
		for(int i=n ; i>=0 ; i--) cin >> c[i];
		
		int t=max(-1,n-k);
		for(int i=0 ; i<=t ; i++) c[i+k]-=c[i];
		
		cout << c[n];
		for(int i=n-1 ; i>t ; i--) cout << " " << c[i];
		cout << endl;
	}
}
