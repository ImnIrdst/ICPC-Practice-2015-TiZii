#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int tc, t=1; cin >> tc;
	while(tc--){
		int n,m; cin >> n; 
		for(int i=1 ; i<=n ; i++){
			cin >> m; if(i==n/2+1) printf("Case %d: %d\n", t++, m);
		}
	}
	return 0;
}