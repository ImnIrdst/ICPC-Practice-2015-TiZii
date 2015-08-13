#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define ST1 1
#define ST2 2
#define EQU 3

using namespace std;

const int MAX = 1000+10;

int dp[MAX][MAX], path[MAX][MAX];

int main(){
	string str1, str2;
	while(getline(cin,str1) && getline(cin,str2)){
		memset(dp,0,sizeof dp); 
		sort(str1.begin(),str1.end());
		sort(str2.begin(),str2.end());
		for(int i=1 ; i<=str1.length()  ; i++){
			for(int j=1 ; j<=str2.length() ; j++){
				if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1]+1, path[i][j]=EQU;
				else if(dp[i-1][j]>dp[i][j-1]){
					 dp[i][j] = dp[i-1][j]; path[i][j]=ST1;
				}
				else dp[i][j] = dp[i-1][j], path[i][j]=ST2;
			}
		}
		string ans="";
		for(int i=str1.length(), j=str2.length() ; i && j ; ){
			if(path[i][j]==EQU) ans+=str1[i-1], i=i-1, j=j-1;
			if(path[i][j]==ST1) i=i-1;
			if(path[i][j]==ST2) j=j-1;
		}
		sort(ans.begin(),ans.end());
		cout << ans << endl;
	}
}