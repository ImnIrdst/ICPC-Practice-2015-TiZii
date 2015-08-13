#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define MAX (100+20)

using namespace std;

string str1, str2; int dp[MAX][MAX]={0};

int main(){
	int t=1;
	while(getline(cin,str1) && str1!="#"){ getline(cin,str2);
		memset(dp,0,sizeof dp);
		// for(int i=1 ; i<=str1.length() ; i++) dp[i][1]=(str1[i-1]==str2[0]);
		// for(int i=1 ; i<=str2.length() ; i++) dp[1][i]=(str1[0]==str2[i-1]);
		for(int i=1 ; i<=str1.length() ; i++){
			for(int j=1 ; j<=str2.length() ; j++){
				dp[i][j]=max( 
							max(dp[i-1][j],dp[i][j-1])
								,dp[i-1][j-1]+(str1[i-1]==str2[j-1]));
			}
		}
		// for(int i=0 ; i<=str1.length() ; i++){
		// 	for(int j=0 ; j<=str2.length() ; j++){
		// 		//dp[i][j]=max(max(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+(str1[i]==str2[j]);
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		printf("Case #%d: you can visit at most %d cities.\n", t++, dp[str1.length()][str2.length()]);
	}
}