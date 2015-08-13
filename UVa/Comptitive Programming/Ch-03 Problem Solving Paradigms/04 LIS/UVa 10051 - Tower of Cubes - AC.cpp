#include <iostream>
#include <string>

using namespace std;

int main(){
	int tc; cin >> tc; cin.ignore(), cin.ignore();
	while(tc--){
		int n=0, dp[25+10][25+10]; string str[25+10];
		while(getline(cin,str[n]) && str[n]!="") n++;

		int ans = 0;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<str[i].length() ; j++){
				bool ok=1;
				for(int k=0; k<dp[i][j] ; k++){
					if(str[i-k][j]=='0' || str[i][j-k]=='0'){
						ok=0;
					}
				}
				if(ok) dp[i+1][j+1] = dp[i][j]+1, ans = max(ans, dp[i][j]+1);
			}
		}

		cout << ans << endl; if(tc) cout << endl;
	}
}