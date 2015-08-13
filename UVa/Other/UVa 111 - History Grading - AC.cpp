#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <sstream>
#define INF (int)1e9
#define int64 long long

using namespace std;

int a[40],b[40];//a => sequence c in problem , b sequence r in problem
int dp[40][40];

int main(){
	int n,tmp; cin >> n;
	for(int i=0 ; i<n ; i++){
		cin >> tmp;
		a[tmp-1]=i;//???
	}
	string str; stringstream sstr; getline(cin,str);
	while(getline(cin,str)){
		sstr << str; int ans=0;
		for(int i=0 ; i<n ; i++){
			sstr >> tmp;
			b[tmp-1]=i;//???
		}
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout << dp[n][n] << endl;
		sstr.clear();
	}
	return 0;
}