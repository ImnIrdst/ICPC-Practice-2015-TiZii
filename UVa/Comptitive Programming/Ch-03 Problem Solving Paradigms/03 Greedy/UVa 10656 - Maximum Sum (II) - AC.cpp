#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9

using namespace std;

int main(){
	int n,tmp;
	while(cin >> n && n){
		bool printzero=true,first=true;
		for(int i=0 ; i<n ; i++){
			cin >> tmp;
			if(tmp!=0) {
				printzero=false;
				if(!first) cout << " "; first=false;
				cout << tmp; 
			}
		}
		if(printzero) cout << 0;
		cout << endl;
	}
	return 0;
}