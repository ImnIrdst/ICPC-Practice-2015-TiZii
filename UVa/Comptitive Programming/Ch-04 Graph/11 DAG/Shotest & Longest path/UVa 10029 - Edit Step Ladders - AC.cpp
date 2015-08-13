#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int> dp; 

int main(){
	string str; int ans=0;
	while(cin >> str){
		int Max = 1;
		for(int i=0 ; i<=str.size() ; i++){
			for(char c='a' ; c<='z' ; c++ ){
				string tmp(str); tmp.insert(i,1,c);
				if(tmp < str && dp.count(tmp))
					Max = max(Max, dp[tmp]+1);
			}
		}
		for(int i=0 ; i<str.size() ; i++){
			string tmp(str); tmp.erase(i,1);
			if(tmp < str && dp.count(tmp))
				Max = max(Max, dp[tmp]+1);
		}
		for(int i=0 ; i<str.size() ; i++){
			for(char c='a' ; c<='z' ; c++ ){
				string tmp(str); tmp[i]=c;
				if(tmp < str && dp.count(tmp))
					Max = max(Max, dp[tmp]+1);
			}
		}
		dp[str] = Max; ans = max(ans, Max);
	}
	cout << ans << endl;
}