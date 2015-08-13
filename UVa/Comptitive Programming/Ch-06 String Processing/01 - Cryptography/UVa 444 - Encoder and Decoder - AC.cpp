#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string Int2Str(int i){
	stringstream sstr; sstr << i;
	string ret; sstr >> ret;
	reverse(ret.begin(), ret.end());
	return ret;
}

int Str2Int(string s){
	stringstream sstr; sstr << s;
	int ret; sstr >> ret; return ret;
}

int main(){
	string str;
	while(getline(cin, str)){
		string ans="";
		if(isdigit(str[0])){
			string tmp="";
			//reverse(ans.begin(), ans.end());
			for(int i=str.length()-1 ; i>0 ; i-=2){
				tmp+=str[i]; tmp+=str[i-1]; 
				if(str[i]=='1') tmp+=str[i-2], i--;
				ans+=char(Str2Int(tmp)); tmp="";
			}
		}
		else{
			for(int i=str.length()-1 ; i>=0 ; i--){
				ans+=Int2Str(int(str[i]));
			}
			
		}
		
		cout << ans << endl;
	}
}