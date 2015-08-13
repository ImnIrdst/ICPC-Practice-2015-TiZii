#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef vector<char> vc;
typedef vector< vc > vvc;

const int MAX = 200 + 10; 

int main(){
	set<string> ignores; string str, str2;
	while(getline(cin, str) && str!="::")
		ignores.insert(str);

	multimap<string, string> mp;
	while(getline(cin, str)){
		for(int i=0 ; i<str.size() ; i++){
			str[i] = tolower(str[i]);
		}
		for(int i=0 ; i<str.size() ; i++){
			if(!isalpha(str[i])) continue;
			str2 = ""; int j=i ;
			for(j=j ; j<str.size() && isalpha(str[j]) ; j++) 
				str2+=str[j];
			if(!ignores.count(str2)){
				for(int k=0 ; k<str.size() ; k++){
					str2[k] = toupper(str2[k]);
				}
				string str3 = str; str3.replace(i,str2.size(), str2);
				mp.insert(make_pair(str2,str3));
			}
			i=j;
		}
	}
	multimap<string, string>::iterator it;
	for(it=mp.begin() ; it!=mp.end() ; it++){
		cout << it->second << endl;
	}
}