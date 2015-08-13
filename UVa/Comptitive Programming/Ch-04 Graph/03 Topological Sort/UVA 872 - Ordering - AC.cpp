#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <sstream>
#include <set>
#define INF (int)1e9
#define MAX 100

using namespace std;

int cons[MAX+10][MAX+10],n; char a[MAX],ch1,ch2; bool hasAns;

int check(char ch, string& str){
	for(int i=0 ; i<str.length() ; i++){
		if(str[i]==ch || cons[ch][str[i]]) return 0;
	}
	return 1;
}

int solve(string ans){ // 1 back track to first, 0 back track to prev
	if(ans.length()==2*n){
		cout << ans.substr(0,2*n-1) << endl; hasAns=true; return 0;}
	for(int i=0 ; i<n ; i++){
		if(check(a[i],ans)) solve(ans+a[i]+" ");
	}
	return 0;
}

int main(){
	stringstream sin;
	int tc; cin >> tc; string str; getline(cin,str);
	while(tc--){
		getline(cin, str); getline(cin, str); 
		n=0; hasAns=false; memset(cons, 0, sizeof cons);
		sin.clear(); sin << str; while(sin >> a[n]) n++;
		getline(cin, str); sin.clear(); sin << str;
		while(sin >> ch1 >> ch2 >> ch2) cons[ch1][ch2]=1;
		sort(a,a+n); solve("");
		if(!hasAns) cout << "NO" << endl;
		if(tc!=0) cout << endl;
	}
	return 0;
}