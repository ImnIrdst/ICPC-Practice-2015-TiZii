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

int main(){
	int n,t=1,tmp;
	while(cin >> n && n ){
		int ans=0;
		while(n--){
			cin >> tmp;
			if(tmp) ans++;
			else	ans--;
		}
		printf("Case %d: %d\n", t++ , ans);
	}	
	return 0;
}