#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9

using namespace std;

int n,d,r,a[100+10],b[100+10];

int main(){
	while(cin >> n >> d >> r && (n || r || d)){
		for(int i=0 ; i<n ; i++) cin >> a[i];
		for(int i=0 ; i<n ; i++) cin >> b[i];
		sort(a,a+n); sort(b,b+n,::greater<int>()); int ans=0;
		for(int i=0 ; i<n ; i++){
			if(a[i]+b[i]>d) ans+=a[i]+b[i]-d;
		}
		cout << ans*r << endl;
	}
	return 0;
}