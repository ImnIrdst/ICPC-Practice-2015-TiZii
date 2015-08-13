#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <map>
#define INF (int)1e9
#define int64 long long
#define mapsi map<string,int>

using namespace std;

int main(){
	int n; cin >> n; string str;  mapsi mp; getline(cin, str);
	while(n--){
		getline(cin,str);
		stringstream sstr; sstr << str; sstr >> str;
		if(!mp[str]) mp[str]=1;
		else mp[str]++;
	}
	for(mapsi::iterator itr=mp.begin() ; itr!=mp.end() ; itr++){
		cout << itr->first  << " " << itr->second << endl; 
	}
	return 0;
}