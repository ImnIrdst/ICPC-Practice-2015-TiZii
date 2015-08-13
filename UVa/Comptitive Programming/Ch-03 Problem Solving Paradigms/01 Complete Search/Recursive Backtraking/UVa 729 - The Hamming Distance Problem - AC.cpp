#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, h;

void solve(string bit, int i, int one){// d = depth
	//cout << bit << endl;
	if(i==n){
		if(one!=h) return;
		cout << bit << endl; return;
	}
	solve(bit+'0', i+1, one);
	solve(bit+'1', i+1, one+1);
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> h;
		solve("",0,0); 
		if(tc) cout << endl;
	}
}