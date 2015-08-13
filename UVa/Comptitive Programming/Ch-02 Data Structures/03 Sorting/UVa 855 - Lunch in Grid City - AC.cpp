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

int a[50000+10]={0}, s[50000+10]={0};

int main(){
	int tc; cin >> tc;
	while(tc--){
		int c,r,n;
		cin >> c >> r >> n;
		for(int i=0 ; i<n ; i++){
			cin >> s[i] >> a[i];
		}
		sort(a,a+n); sort(s,s+n);
		if(n%2){ 
			printf("(Street: %d, Avenue: %d)\n",s[n/2], a[n/2]);
		}else{n--;
			printf("(Street: %d, Avenue: %d)\n",s[n/2], a[n/2]);
		}
	}
	return 0;
}