#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		int n, ans=-1*INF, tmp; cin >> n;
		while(n--){
			cin >> tmp; ans=max(ans,tmp);
		}
		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}