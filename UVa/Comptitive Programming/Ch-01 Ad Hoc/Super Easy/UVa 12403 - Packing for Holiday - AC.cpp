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
	int tc, t=1; cin >> tc;
	while(tc--){
		int a,flag=0;
		for(int i=0 ; i<3 ; i++){
			cin >> a;
			if(a>20)
				flag=1;
		}
		printf("Case %d: %s",t++,(flag ? "bad" : "good"));
	}
	return 0;
}