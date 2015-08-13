#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define INF (int)1e9
#define int64 long long

using namespace std;

map<string, int> mp; set<string> ans;
set<string>::iterator itr;

int main(){
	string tmp,tmp2; int n=0;
	while(cin >> tmp && tmp!="#"){
		ans.insert(tmp);
		transform(tmp.begin(),tmp.end(),tmp.begin(),::toupper); sort(tmp.begin(),tmp.end());
		mp[tmp]++;
	}
	for(itr=ans.begin() ; itr!=ans.end() ; itr++){ 
		string tmp=*itr;
		transform(tmp.begin(),tmp.end(),tmp.begin(),::toupper); sort(tmp.begin(),tmp.end());
		if(mp[tmp]==1)
			cout << *itr << endl;
	}
	return 0;
}