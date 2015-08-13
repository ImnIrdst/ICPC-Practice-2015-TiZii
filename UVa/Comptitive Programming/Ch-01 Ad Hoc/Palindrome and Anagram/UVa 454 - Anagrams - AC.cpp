#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<string, string> pss;

string TrimSort(const string& str){
	stringstream sstr; sstr << str;
	string ret = "", tmp;
	while(sstr >> tmp) ret+=tmp;
	sort(ret.begin(), ret.end());
	return ret;
}

int main(){
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while( tc-- ){
		string tmp;
		pss s[100+10]; int n;
		for(n=0 ; getline(cin, tmp) && tmp!="" ; n++){
			s[n]=pss(tmp,TrimSort(tmp));
		}
		sort(s,s+n);
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				if(s[i].second==s[j].second){
					cout << s[i].first << " = " << s[j].first << endl;
				}
			}
		}
		if(tc) cout << endl;
	}
}