#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string org; int n, m, tmp; 

void solve(int id, string tmp){
	if(id>org.size()) return;
	if(tmp.size()==m){
		string space=""; 
		//for(int i=0 ; i<m ; i++) cout << (int)tmp[i]; cout << endl;
		for(int i=0 ; i<org.size() ; i++){ 
			if(tmp.find(org[i])!=-1) continue;
			cout << space << (int)org[i]; space=" ";
		} cout << endl;
		return;
	}
	solve(id+1, tmp); solve(id+1, tmp+org[id]);
}

int main(){
	string blankline="";
	while(cin >> n && n){ org="";
		for(int i=0 ; i<n ; i++) 
			cin >> tmp, org+=(char)tmp;
		m = org.length()-6;
		cout << blankline; blankline="\n"; solve(0,""); 
	}
}