#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <set>
#define inf (int)1e9

using namespace std;

int ans,n; char a[15][15];

void solve(int col, int row, int diag1, int diag2){//diag1,diag2 -> bitmasks for diagonals
	if(row==(1<<n)-1){
		ans++; return;
	}
	for(int i=0 ; i<n ; i++){//Uneficient cireteria can cause TLE, Just Use Bitwise operation
		if(!(((row>>i) | (diag1>>(col+i)) | (diag2>>(n+col-i))) & 1) && a[col][i]!='*'){
			solve(col+1,row|(1<<i),diag1|(1<<(col+i)),diag2|(1<<(n+col-i)));
		}
	}
}

int main(){
	int t=1;
	while(scanf("%d",&n) && n){
		ans=0;
		//clock_t start=clock();
		for(int i=0 ; i<n ; i++){
			scanf("%s",a[i]);
		}
		solve(0,0,0,0); printf("Case %d: %d\n",t++, ans);
		//cout << (clock()-start)/(double)CLOCKS_PER_SEC << endl;
	}
	return 0;
}