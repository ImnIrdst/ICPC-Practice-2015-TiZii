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

bool cmp(int a, int b){return a>b;}

int main(){
	int tc, t=1; cin >> tc;
	while(tc--){
		int a[50]={0};
		int r,c,m,n; cin >> r >> c >> m >> n;
		for(int i=0 ; i<r ; i++){
			for(int j=0 ; j<c ; j++){
				char tmp; cin >> tmp;
				a[tmp-'A']++;
			}
		}
		sort(a,a+50,cmp);
		int ans=0;
		for(int i=0 ; i<50 ; i++){
			if(a[i]==a[0]) ans+=a[i]*m;
			else ans+=a[i]*n;
		}
		printf("Case %d: %d\n", t++ , ans);
	}
	return 0;
}