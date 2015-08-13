#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	string one="one", two="two", three="three", str;
	int tc; cin >> tc;
	while(tc--){
		cin >> str;
		if(str.length()==5) cout << 3 << endl;
		else{
			int cnt=0;
			for(int i=0 ; i<str.length() ; i++)
				if(str[i]==one[i]) cnt++;
			if(cnt>=2)	cout << 1 << endl;
			else 		cout << 2 << endl;
		}
	}
	return 0;
}