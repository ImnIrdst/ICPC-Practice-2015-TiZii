#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

int isprime; vector<int> p,a;

int main(){
	for(int i=2 ; p.size()<=3501 ; i++){
		isprime=1;
		for(int j=2 ; j*j<=i ; j++){
			if(i%j==0){ isprime=0; break;}
		}
		if(isprime) p.push_back(i);
	}
	int n;
	while(cin >> n && n){
		a.clear();
		for(int i=0 ; i<n ; i++) 
			a.push_back(i+1);
		int size=n, num=0, i=0, m;
		while(--n){
			m=p[i++]-1;
			num+=m; num%=size--;
			a.erase(a.begin()+num);
		}
		cout << a[0] << endl;
	}
	return 0;
}