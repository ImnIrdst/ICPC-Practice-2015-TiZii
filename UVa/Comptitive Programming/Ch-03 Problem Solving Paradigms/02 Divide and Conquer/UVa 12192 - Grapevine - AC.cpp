#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int Max = 500+10;

int a[Max][Max];

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) && (n||m)){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				scanf("%d", &a[i][j]);
			}
		}

		int q;
		cin >> q;
		while(q--){
			int ans = 0, side;
			int L, U; scanf("%d %d", &L, &U);
			for(int i=0 ; i<n ; i++){
				int j = lower_bound(a[i], a[i]+m, L)-a[i];
				for(side=ans ; j+side<m && i+side<n ; side++){
					if(a[i+side][j+side]<L || a[i+side][j+side]>U) break;
				}
				ans = max(ans, side);
			}
			printf("%d\n", ans);
			if(!q) printf("-\n");
		}
	}
}