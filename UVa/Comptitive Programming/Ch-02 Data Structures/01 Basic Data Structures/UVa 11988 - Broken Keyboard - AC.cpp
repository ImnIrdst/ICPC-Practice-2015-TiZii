#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <list>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	string str;
	while(cin >> str){
		list<char> ans; list<char>::iterator itr=ans.begin();
		for(int i=0 , j=0; i<str.length() ; i++){
			if(str[i]=='[') itr=ans.begin();
			else if( str[i]==']') itr=ans.end();
			else ans.insert(itr,str[i]);
		}
		for(itr=ans.begin() ; itr!=ans.end() ; itr++)
			cout << *itr;
		cout << endl;
	}
	return 0;
}