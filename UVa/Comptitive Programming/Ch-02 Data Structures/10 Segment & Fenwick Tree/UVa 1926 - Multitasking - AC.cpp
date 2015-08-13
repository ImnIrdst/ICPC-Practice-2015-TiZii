#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <bitset>
#define MAX 1000000+10

using namespace std;

bitset<MAX> a; // marked intervals,
int n,m; bool ans;

bool check(int l , int r){
	for(int i=l ; i<r && i<=1000000 ; i++){
		if(a[i]) return false;
		a[i]=1;
	}
	return true;
}

int main(){
	
	while(cin >> n >> m && (n || m)){
		int l,r; ans=true; a.reset();
		for(int i=0 ; i<n ; i++){
			cin >> l >> r;
			if(!check(l,r)) ans=false;
			//cout << a.to_string() << endl;//for debug
		}
		int x;
		for(int i=0 ; i<m ; i++){
			cin >> l >> r >> x;
			while(l<=MAX){
				if(!check(l,r) && ans) ans=false;
				r+=x; l+=x;
			}
			//cout << a.to_string() << endl;
		}
		cout << (ans ? "NO CONFLICT" : "CONFLICT") << endl;
	}
	return 0;
}