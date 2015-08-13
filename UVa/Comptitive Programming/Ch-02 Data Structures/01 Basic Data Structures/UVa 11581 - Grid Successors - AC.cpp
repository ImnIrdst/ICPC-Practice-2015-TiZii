#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#define INF (int)1e9
#define int64 long long

using namespace std;

int g[5][5]={0},n=3;

void f(){
	int tmp[5][5]={0};
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			tmp[i][j]+=g[i-1][j]; tmp[i][j]+=g[i+1][j];
			tmp[i][j]+=g[i][j-1]; tmp[i][j]+=g[i][j+1];
			tmp[i][j]%=2;
		}
	}
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			g[i][j]=tmp[i][j];
}

bool check(){
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			if(g[i][j]>0) return true;
	return false;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=n ; j++)
				scanf("%1d",&g[i][j]);
		int ans=-1;
		while(check()){
			f(); ans++;
		}
		cout << ans << endl;
	}
	return 0;
}