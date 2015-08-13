#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;

int n, m, cs=1; string rule; vs words;

void solve(string word, int d){// d = depth
	if(d == rule.length()){
		cout << word << endl; return;
	}
	if(rule[d]=='#'){
		for(int i=0 ; i<n ; i++){
			solve(word+words[i], d+1);
		}
	}else{
		for(int i=0 ; i<10 ; i++){
			solve(word+char('0'+i), d+1);
		}
	}
}

int main(){
	while(cin >> n){
		words.resize(n);
		for(int i=0 ; i<n ; i++) 
			cin >> words[i];
		cin >> m;
		for(int i=0 ; i<m ; i++){
			cout << "--" << endl;
			cin >> rule; solve("",0);
		}
	}
}