#include <iostream>

using namespace std;

int coins[] = {50,25,10,5,1};
long long dp[7489 +10]={0};

int main(){
	dp[0]=1;
	for(int j=0 ; j<5 ; j++){
		for(int i=0 ; i<7489+10 ; i++){
			if(i>=coins[j]){
				dp[i]+=dp[i-coins[j]];
			}
		}
	}
	int n1, n2, n; char c;
	while(cin >> n) cout << dp [n] << endl; 
}