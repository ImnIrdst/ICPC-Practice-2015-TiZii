#include <iostream>

using namespace std;

const int n = 1e6+10;

int dp[n]={0};

int SumofDigits(int x){
	int sum=0;
	while(x){
		sum+=x%10; x/=10; 
	}
	return sum;
}

int main(){
	for(int i=1 ; i<n ; i++){
		if(dp[i]==0) cout << i << endl;
		dp[i+SumofDigits(i)]++;
	}
}