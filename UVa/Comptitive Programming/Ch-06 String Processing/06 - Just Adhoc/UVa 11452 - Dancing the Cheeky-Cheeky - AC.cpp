#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>


using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		string str,step; cin >> str;
		for(int i=str.size() ; i>0 ; i--){
			if(str.substr(i).find(str.substr(0,i))==0){
				step=str.substr(0,i); break; 
			}
		}
		for(int i=step.size(), j=0 ; i<str.size()+8 ; i++){
			if(i>=str.size()) cout << step[j];
			j++; j%=step.size();
		}
		cout << "..." << endl;
	}
}
