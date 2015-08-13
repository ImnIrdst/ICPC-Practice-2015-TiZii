#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

int rookcnt(vector<string>& board){
	int ret=0;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			if(board[i][j]=='r') ret++;
		}
	}
	return ret;
}

int valid(vector<string>& board, int ii, int jj){
	if(board[ii][jj]=='X') return 0;
	for(int i=ii ; i<n ; i++){
		if(board[i][jj]=='X') break;
		if(board[i][jj]=='r') return 0; 
	}
	for(int i=ii ; i>=0 ; i--){
		if(board[i][jj]=='X') break;
		if(board[i][jj]=='r') return 0; 
	}
	for(int j=jj ; j<n ; j++){
		if(board[ii][j]=='X') break;
		if(board[ii][j]=='r') return 0; 
	}
	for(int j=jj ; j>=0 ; j--){
		if(board[ii][j]=='X') break;
		if(board[ii][j]=='r') return 0; 
	}
	return 1;
}

int solve(vector<string> board, int lev){
	if(lev==n*n) return rookcnt(board);

	int Max=-1;
	Max = solve(board, lev+1);
	if(valid(board,lev/n,lev%n)){
		vector<string> tmp = board; tmp[lev/n][lev%n]='r';
		Max = max(Max,solve(tmp,lev+1));
	}
	return Max;
}

int main(){
	while(cin >> n && n){
		vector<string> board(n);
		for(int i=0 ; i<n ; i++) cin >> board[i];
		cout << solve(board,0) << endl;
	}
}