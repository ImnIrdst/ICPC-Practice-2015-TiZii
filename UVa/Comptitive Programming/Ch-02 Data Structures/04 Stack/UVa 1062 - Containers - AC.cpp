#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

typedef stack<char > stc;
typedef vector<stc > vstc;
typedef vector<int > vi;

int main(){
	string str; int cs=1;
	while(cin >> str && str!="end"){
		vstc stk; stk.push_back(stc());

		for(int i=0 ; i<str.size() ; i++){
			bool inserted=0;
			for(int j=0 ; j<stk.size() ; j++){
				if(stk[j].empty() || stk[j].top()>=str[i]){
					stk[j].push(str[i]); inserted=1; break;
				}
			}
			if(!inserted) stk.push_back(stc()), stk[stk.size()-1].push(str[i]);
		}
		cout << "Case " << cs++ << ": " << stk.size() << endl;
	}
}