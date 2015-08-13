#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <set>
#define INF (int)1e9

using namespace std;

int q[9],tmpq[9],n=9,dp[100][9],top=0;

int check(int idx){
	for(int i=1 ; i<idx ; i++){
		if(tmpq[i]==tmpq[idx] || (abs(tmpq[i]-tmpq[idx])==abs(i-idx))) return 0;
	}
	return 1;
}

int posmod(int n, int m){return (n%m>0? n%m : (n%m)+m);}

void solve(int idx){
	if((idx>0 && (tmpq[idx-1]<1 || tmpq[idx-1]>8)) || !check(idx-1) ) return;
	if(idx==n){
		memcpy(dp[top],tmpq,sizeof tmpq); top++;
	}
	for(int i=1 ; i<n ; i++){
		if(idx==0 && i>1) return;
		tmpq[idx]=i;
		solve(idx+1);
	}
}

int main(){
	int t=1; solve(0);
	while(cin >> q[1]){
		//int start=clock();
		for(int i=2 ; i<n ; i++) cin >> q[i];
		int ans=INF,cnt;
		for(int i=0 ; i<100 ; i++){
			cnt=0;
			for(int j=1 ; j<9 ; j++){
				if(q[j]!=dp[i][j]) cnt++;
			}
			ans=min(cnt,ans);
		}
		printf("Case %d: %d\n",t++, ans);
		//cout << clock()-start << endl;
	}
	return 0;
}