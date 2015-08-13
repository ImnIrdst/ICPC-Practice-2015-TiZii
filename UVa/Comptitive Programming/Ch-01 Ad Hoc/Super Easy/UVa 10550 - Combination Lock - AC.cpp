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
	int a[4];
	while(cin >> a[0]){
		for(int i=1 ; i<4 ; i++) cin >> a[i];
		int ans=360*3;
		ans+=( a[0]>a[1])? (a[0]-a[1])*9 : (a[1]-a[0]+40)*9 );
		ans+=( a[2]>a[1])? (a[2]-a[1])*9 : (a[1]-a[2]+40)*9 );
		ans+=( a[2]>a[3])? (a[2]-a[3])*9 : (a[3]-a[2]+40)*9 );
		cout << ans << endl;
	}
	return 0;
}