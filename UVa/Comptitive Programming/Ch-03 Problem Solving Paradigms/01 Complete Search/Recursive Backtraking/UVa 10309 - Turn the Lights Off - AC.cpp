#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <map>
#define INF (int)1e9

using namespace std;

char a[15][15],tmp[15][15]; map<char,char> mp; int n=10;

void toggle(int i, int j){
	tmp[i][j]=mp[tmp[i][j]];
	if(i<9) tmp[i+1][j]=mp[tmp[i+1][j]];
	if(j<9) tmp[i][j+1]=mp[tmp[i][j+1]];
	if(i>0) tmp[i-1][j]=mp[tmp[i-1][j]];
	if(j>0) tmp[i][j-1]=mp[tmp[i][j-1]];
}

int alloff(){
	for(int j=0 ; j<n ; j++){
		if(tmp[9][j]=='O') return 0;
	}
	return 1;
}

int main(){
	string str; mp['#']='O'; mp['O']='#';
	while(cin >> str && str!="end"){
		int ans=101;
		for(int i=0 ; i<n ; i++) cin >> a[i];
		for(int bitset=0 ; bitset<(1<<n) ; bitset++){
			int cnt=0; memcpy(tmp,a,sizeof a);
			for(int i=0 ; i<n ; i++) if(bitset&(1<<i)) toggle(0,i),cnt++;
			for(int i=1 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					if(tmp[i-1][j]=='O') toggle(i,j),cnt++;
				}
				if(cnt>=ans) break;
			}
			if(cnt < ans && alloff()) ans=cnt;
		}
		if(ans==101) ans=-1;
		cout << str << " " << ans << endl;
	}
	return 0;
}