#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define offset 1000*40

using namespace std;

int n, m, a[40+10]; bool isIncome[40+10],isExpense[40+10]; 
int dpIncome[2*1000*40+10][40+10],dpExpense[2*1000*40+10][40+10];

bool solve(int sum, int i){
	if(i==n && sum==m) return 1;
	if(i==n && sum!=m) return 0;
	int& dppinc=dpIncome[sum+offset][i];
	int& dppexp=dpExpense[sum+offset][i];
	
	if(dppinc ==-1) dppinc=solve(sum+a[i],i+1);
	isIncome[i]|=dppinc;
	if(dppexp ==-1) dppexp=solve(sum-a[i],i+1);
	isExpense[i]|=dppexp;
	return (dppinc || dppexp);
}

int main(){
	
	while(cin >> n >> m && (m || n)){
		string ans="";
		for(int i=0 ; i<n ; i++) cin >> a[i];
		memset(dpIncome,-1,sizeof dpIncome); memset(dpExpense,-1,sizeof dpExpense);
		memset(isIncome,0 ,sizeof isIncome); memset(isExpense,0 ,sizeof isExpense);
		if(solve(0,0)==0) ans="*";
		else for(int i=0 ; i<n ; i++){
			if(isIncome[i] && !isExpense[i]) ans+="+";
			else if(!isIncome[i] && isExpense[i])ans+="-";
			else if(isIncome[i] && isExpense[i]) ans+="?";
		}
		cout << ans << endl;
	}
	return 0;
}