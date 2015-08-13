#include <iostream>

using namespace std;

int card[5][5], mark[5][5], n=5;

bool SearchMarkCheck(int num){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			if(card[i][j]==num) mark[i][j]=1;
		}
	}

	for(int i=0 ; i<n ; i++){
		int sum=0;
		for(int j=0 ; j<n ; j++) sum+=mark[i][j];
		if(sum==5) 
			return 1;
	}
	for(int i=0 ; i<n ; i++){
		int sum=0;
		for(int j=0 ; j<n ; j++) sum+=mark[j][i];
		if(sum==5) 
			return 1;
	}
	if(mark[0][0] && mark[1][1] && mark[3][3] && mark[4][4]) 
		return 1;
	if(mark[0][4] && mark[1][3] && mark[3][1] && mark[4][0]) 
		return 1;
	return 0;
}

int main(){
	int tc; 
	cin >> tc;
	while(tc--){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				mark[i][j]=1;
				if(i==2 && j==2) continue;
				cin >> card[i][j]; mark[i][j]=0;
			}
		}

		int num, found=0;
		for(int i=0 ; i<75 ; i++){
			cin >> num;
			if(!found && SearchMarkCheck(num)){
				found=1; cout << "BINGO after " << i+1 << " numbers announced" << endl;
			}
		}
	}
}