#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>


using namespace std;

int dp[3000+10][3000+10], path[3000+10][3000+10]; vector<string> vs1, vs2; bool first;

void printPath(int i, int j){
	if(i==0 || j==0) return;
	if(path[i][j]==0){
		printPath(i-1,j-1); 
		if(!first) cout << ' '; first = false;
		cout << vs1[i-1];
	}
	if(path[i][j]==1) printPath(i-1,j);
	if(path[i][j]==2) printPath(i,j-1);
}

int main(){
	string tmp;
	while(cin >> tmp){
		vs1.clear(); if(cin.eof()) return 0;
		while(tmp[0] != '#'){
			vs1.push_back(tmp); cin >> tmp; 
		}//cin.ignore();

		vs2.clear(); cin >> tmp;
		while(tmp[0] != '#'){
			vs2.push_back(tmp); cin >> tmp;
		}//cin.ignore();

		memset(dp, 0, sizeof dp);
		for(int i=1 ; i<=vs1.size() ; i++){
			for(int j=1 ; j<=vs2.size() ; j++){
				if(vs1[i-1]==vs2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1 , path[i][j]=0;
				}else if(dp[i-1][j] >  dp[i][j-1]) {
					dp[i][j]=dp[i-1][j], path[i][j]=1;
				}else if(dp[i-1][j] <= dp[i][j-1]){
					dp[i][j]=dp[i][j-1], path[i][j]=2;
				}
			}
		}
		first=true;
		printPath(vs1.size(), vs2.size()); printf("\n");
	}
}