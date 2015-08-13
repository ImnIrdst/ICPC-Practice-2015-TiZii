#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <set>


using namespace std;

int CntEx(string str, set<string>& st){
	for(int i=0 ; i<str.length() ; i++){
		if(!isalpha(str[i])) str[i]=' ';
		if(isupper(str[i])) str[i]=str[i]-'A'+'a';
	}
	stringstream sstr(str); 
	string s; int cnt = 0;
	while(sstr >> s){
		if(st.count(s)) cnt++;
	}
	return cnt;
}

int main(){
	int n, m, cs=1;
	while(cin >> n >> m){
		set<string> st; string s;
		for(int i=0 ; i<n ; i++){
			cin >> s; st.insert(s);
		}
		vector<string> vs; int Max=-1;
		cin.ignore(); vector<int> vi;
		for(int i=0 ; i<m ; i++){
			getline(cin, s); vs.push_back(s); 
			vi.push_back(CntEx(s,st));
			Max = max(Max, CntEx(s,st));
		}
		cout << "Excuse Set #" << cs++ << endl;
		for(int i=0 ; i<m ; i++){
			if(vi[i]==Max){
				cout << vs[i] << endl;
			}
		}
		cout << endl;
	}
}