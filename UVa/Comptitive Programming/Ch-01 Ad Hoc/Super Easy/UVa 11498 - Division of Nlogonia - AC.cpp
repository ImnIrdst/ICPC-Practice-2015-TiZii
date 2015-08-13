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

int oa,ob, pa , pb;// o = offset, p = point

int main(){
	int n;
	while(cin >> n && n){
		cin >> oa >> ob;
		while(n--){
			cin >> pa >> pb;
			if(pa==oa || pb==ob) cout << "divisa" << endl; 
			if(pa>oa && pb>ob) cout << "NE" << endl;
			if(pa<oa && pb>ob) cout << "NO" << endl;
			if(pa>oa && pb<ob) cout << "SE" << endl;
			if(pa<oa && pb<ob) cout << "SO" << endl;
		}
	}
	return 0;
}