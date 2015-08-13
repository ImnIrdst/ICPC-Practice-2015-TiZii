#include <set>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <functional>

using namespace std;

char cap1[6][6], cap2[6][6], pass[6]; int k, cnt, terminatee;

int IsInCol(int j, char c){
	bool found1=false, found2=false;
	for(int i=0 ; i<6 ; i++) if(cap1[i][j]==c) found1=true;
	for(int i=0 ; i<6 ; i++) if(cap2[i][j]==c) found2=true;
	return found1 && found2;
}

int solve(int j){
	if(j==5 && !terminatee){
		pass[j]='\0'; cnt++; if(cnt==k) cout << pass << endl, terminatee=true;
	}
	for(char c='A' ; c<='Z' && !terminatee ; c++){
		if(IsInCol(j, c)) 
			pass[j]=c, solve(j+1);
	}
}

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		cin >> k; cnt=terminatee=0;
		for(int i=0 ; i<6 ; i++) cin >> cap1[i];
		for(int i=0 ; i<6 ; i++) cin >> cap2[i];
		solve(0);
		if(!terminatee) cout << "NO" << endl;
	}
}