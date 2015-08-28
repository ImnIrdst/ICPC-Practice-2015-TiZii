#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <fstream>
//#define cin fin
#define INF (int)1e9
#define int64 long long

using namespace std;

char a[110][110], b[110][110];

char calc(int x, int y){
	int cnt=0;
	for(int i=x-1 ; i<=x+1 ; i++){
		for(int j=y-1 ; j<=y+1 ; j++){
			if(a[i][j]=='*')
				cnt++;
		}
	}
	return '0'+cnt;
}

int main(){
	//ifstream fin("in.txt");
	int n,m,t=0;// t = number of test case;
	while(cin >> n >> m){
		if(!n && !m) break;
		memset(a,'.',sizeof a);
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=m ; j++){
				cin >> a[i][j];
			}
		}
		if(t++) cout << endl;
		cout << "Field #" << t << ":" << endl;
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=m ; j++){
				if(a[i][j]!='*'){
					b[i][j]=calc(i,j);
				}else b[i][j]='*';
				cout << b[i][j];
			}
			cout << endl;
		}
	}	
	return 0;
}