#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#define INF (int)1e9
#define int64 long long

using namespace std;

string str; int i;

bool match(char a, char b){if(a=='[') return b==']'; if(a=='(') return b==')';}

int main(){
	int tc; cin >> tc; cin.ignore();
	while(tc--){
		getline(cin,str); stack<char> st; 
		for( i=0 ; i<str.size(); i++){
			if(str[i]=='(' || str[i]=='['){
				st.push(str[i]);
			}
			if(str[i]==')' || str[i]==']'){
				if(st.empty() || !match(st.top(),str[i])) break;
				st.pop();
			}	
		}
		if(i==str.size() && st.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}