#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int dp[3000002]={0};
int solve(int a){
	if(a==1) return 1;
	if(a<3000002){
		if(dp[a]!=0) return dp[a];
		if(a%2==1) return dp[a]=1+solve(a*3+1);
		else return dp[a]=1+solve(a/2);
	}
	else{
		if(a%2==1) return 1+solve(a*3+1);
		else return 1+solve(a/2);
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		int i,j,ki;
		cin >> i >> j;
		int Max=0;
		for(int l=min(i,j) ; l<=max(i,j) ; l++){
			//cout << l << endl;
			Max=max(solve(l),Max);
		}
		cout << i << " " << j << " " << Max << endl;
	}	
}
/*
4
1 10
200 100
201 210
900 1000
*/