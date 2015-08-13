#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string,int> mp; string misspellingof; int ansIdx;

void isAdj(string str){
	for(int i=0 ; i<str.length()-1 ; i++){
		string tmp=str; swap(tmp[i],tmp[i+1]);
		if(mp.count(tmp)){
			if(mp[tmp]>ansIdx) misspellingof=tmp, ansIdx=mp[tmp]; 
		}
	}
}

void isWrong(string str){
	for(int i=0 ; i<str.length() ; i++){
		for(char c='a' ; c<='z' ; c++){
			string tmp=str,C; C=c; tmp.replace(i,1,C);
			if(mp.count(tmp)){
				if(mp[tmp]>ansIdx) misspellingof=tmp, ansIdx=mp[tmp]; 
			}
		}
	}
}

void isTooMuch(string str){
	for(int i=0 ; i<str.length() ; i++){
		string tmp=str; tmp.erase(i,1);
		if(mp.count(tmp)){
			if(mp[tmp]>ansIdx) misspellingof=tmp, ansIdx=mp[tmp]; 
		}
	}
}

void isMissing(string str){
	for(int i=0 ; i<str.length()+1 ; i++){
		for(char c='a' ; c<='z' ; c++){
			string tmp=str,C; C=c; tmp.replace(i,0,C);
			if(mp.count(tmp)){
				if(mp[tmp]>ansIdx) misspellingof=tmp, ansIdx=mp[tmp]; 
			}
		}
	}
}

int main(){
	int tc; cin >> tc; string str;
	while(tc--) cin >> str, mp[str]=tc;
	int q; cin >> q;
	while(q--){
		string word; cin >> word; misspellingof=""; ansIdx=-1;
		if(mp.count(word)){
			printf("%s is correct",word.c_str());
		}
		else {
			isAdj(word), isTooMuch(word), isMissing(word), isWrong(word);
			if(ansIdx!=-1) 
				printf("%s is a misspelling of %s",word.c_str(), misspellingof.c_str());
			else 
				printf("%s is unknown",word.c_str());
		}
		printf("\n");
	}
}
/*

10
this
is
a
dictionary
that
we
will
use
for
us
6
su
as
the
dictonary
us
willl

*/