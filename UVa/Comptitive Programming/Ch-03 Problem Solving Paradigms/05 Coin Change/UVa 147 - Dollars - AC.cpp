#include <cstdio>
using namespace std;

int coins[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
long long dp[300000+10]={0};

int main(){
	dp[0]=1;
	for(int j=0 ; j<11 ; j++){
		for(int i=0 ; i<300000+10 ; i++){
			if(i>=coins[j]){
				dp[i]+=dp[i-coins[j]];
			}
		}
	}
	int n1, n2, n; char c;
	while(scanf("%d.%d", &n1, &n2) && (n1||n2)){
		n = n1*100 + n2; printf("%3d.%.2d%17lld\n", n1, n2, dp[n]);
	}
}