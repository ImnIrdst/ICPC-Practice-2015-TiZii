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

set< int > st; int n,m; bitset<15> deb;

int ones(int bitset){
	int cnt=0;
	for(int i=0 ; i<n ; i++){
		if(bitset&(1<<i)) cnt++;
	}
	return cnt;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> m; int bit,ans=n; int a[110]={0},tmp;
		for(int i=0 ; i<m ; i++) for(int j=0 ; j<n ; j++){ cin >> bit; a[i]|=(bit<<j);} 
		//deb=a[i]; cout << deb.to_string() << endl;
		for(int bitset=0 ; bitset<(1<<n) ; bitset++){
			st.clear();
			for(int i=0 ; i<m ; i++){
				//deb=a[i]&bitset; cout << deb.to_string() << endl;
				st.insert(a[i]&bitset);
			}
			if(st.size()==m){
				ans=min(ans,max(1,ones(bitset)));
			}
		}
		cout << ans << endl;
	}
	return 0;
}