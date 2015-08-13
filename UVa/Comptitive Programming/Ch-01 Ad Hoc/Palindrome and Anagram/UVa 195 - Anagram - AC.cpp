#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <set>
#define INF (int)1e9
#define int64 long long

using namespace std;


bool cmp(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}


int main(){
	int tc; cin >> tc;
	while(tc--){
		string str; cin >> str;
		sort(str.begin(),str.end(),cmp); cout << str << endl;
		while(next_permutation(str.begin(),str.end(),cmp)){
			cout << str << endl;
		}
	}
	return 0;
}