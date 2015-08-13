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

int a[20],n,m,sum,ans,ansbit,i,bit; // a -> track durations;

int main(){
	while(cin >> m >> n){
		ans=-1;
		for(int i=0 ; i<n ; i++) cin >> a[i];
		for(bit=0 ; bit<(1<<n) ; bit++){
			for(i=0,sum=0 ; i<n ; i++){
				sum+=a[i]*((bit>>i)&1);
			}
			if(sum<=m && ans<=sum){ ans=sum; ansbit=bit; }
		}
		for(i=0; i<n ; i++){
			if((ansbit>>i)&1) cout << a[i] << " ";
		}
		cout << "sum:" << ans << endl;
	}
	return 0;
}