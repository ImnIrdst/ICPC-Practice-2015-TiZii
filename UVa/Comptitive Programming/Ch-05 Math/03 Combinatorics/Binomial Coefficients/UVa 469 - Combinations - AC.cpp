#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100+10;
typedef long long int64;

int64 c[MAX][MAX]={0};

void Pascal(){
	c[0][1]=1;
	for(int i=1 ; i<MAX ; i++){
		for(int j=1 ; j<=i+1 ; j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
}

int main(){
	int n, m; Pascal();
	while(cin >> n >> m && (n || m)){
		printf("%d things taken %d at a time is %lld exactly.\n", n , m, c[n][m+1]);
	}
}