#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <stack>
#include <map>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	string str; 
	while(getline(cin,str)){
		stack<int> st; stringstream sstr; sstr << str;
		int a; bool flag=true; map<int,int> mp;
		while(sstr >> a && flag){
			if(a<0 && (st.empty() || a>st.top()))
				st.push(a); 
			else if(a<0 && (!st.empty() && a<st.top())) 
				flag=false;
			if(a>0 && (!st.empty() && a==st.top()*-1)){ 
				mp[st.top()*-1]=0;//added after getting wrong: -9 -1 1 9 -9 -7 7 -1 1 9
				st.pop(); 
				if(!st.empty()){
					mp[st.top()*-1]+=a;
					if(mp[st.top()*-1]>=st.top()*-1) flag=false;
				}
			}
			else if(a>0 && (st.empty()/*added after getting wrong*/ || a!=st.top()*-1))  
				flag=false;
		}
		string ans=(flag && st.empty() ? ":-) Matrioshka!" : ":-( Try again.");
		cout << ans << endl;
	}
	
	return 0;
}