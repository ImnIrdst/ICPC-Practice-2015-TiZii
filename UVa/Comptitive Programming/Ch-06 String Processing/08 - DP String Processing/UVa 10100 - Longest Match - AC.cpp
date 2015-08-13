#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int dp[1000+10][1000+10]; vector<string> vs1, vs2;

int main(){
	string tmp1, tmp2, tmp; int cs=1;
	while(getline(cin,tmp1) && getline(cin, tmp2)){
		for(int i=0 ; i<tmp1.size() ; i++) 
			if(!isalpha(tmp1[i]) && !isdigit(tmp1[i])) tmp1[i]=' ';
		for(int i=0 ; i<tmp2.size() ; i++) 
			if(!isalpha(tmp2[i]) && !isdigit(tmp2[i])) tmp2[i]=' ';

		stringstream sstr1(tmp1); vs1.clear();
		while(sstr1 >> tmp) vs1.push_back(tmp);

		stringstream sstr2(tmp2); vs2.clear();
		while(sstr2 >> tmp) vs2.push_back(tmp);

		memset(dp, 0, sizeof dp);
		for(int i=1 ; i<=vs1.size() ; i++){
			for(int j=1 ; j<=vs2.size() ; j++){
				if(vs1[i-1]==vs2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
		int ans = dp[vs1.size()][vs2.size()];
		if(ans == 0) printf("%2d. Blank!\n", cs++);
		if(ans != 0) printf("%2d. Length of longest match: %d\n", cs++, ans);
	}
}