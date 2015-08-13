#include <iostream>
#include <stdio.h>
#include <cmath>
#define MAX (100+10)
using namespace std;

int gcd(int a, int b){if(b==0) return a; return gcd(b,a%b); }

int  s, t, ans[MAX];
void solve(int rem, int Min, int idx){
	if(!rem && idx==t){
		for(int i=0 ; i<idx ; i++){
			if(i==idx-1) printf("%d\n",ans[i]);
			else         printf("%d " ,ans[i]);
		}
	}
	if(!rem || idx==t) return;
	for(int i=Min ; i<=rem ; i++){
		bool check=1;
		for(int j=idx-1 ; j>=0 && check ; j--){
			check &= (gcd(ans[j],i)==1);
		}
		if(check){
			ans[idx]=i; solve(rem-i,i,idx+1);
		}
	}
}

int main(){
	int tc,cs=1; cin >> tc;
	while(tc--){
		cin >> s >> t; 
		printf("Case %d:\n", cs++);
		solve(s,1,0);
	}
	return 0;
}
