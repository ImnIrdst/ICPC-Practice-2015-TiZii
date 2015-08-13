#include <iostream>
#include <string>

using namespace std;

const int MAX = 256;

int isLetter(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

int main(){
	string str;
	while(getline(cin,str)){
		int cnt[MAX]={0};
		for(int i=0 ; i<str.length() ; i++) 
			if(isLetter(str[i])) cnt[str[i]]++;
		int Max = -1;
		for(char i='A' ; i<='Z' ; i++) Max = max(Max,cnt[i]);
		for(char i='a' ; i<='z' ; i++) Max = max(Max,cnt[i]);
		for(char i='A' ; i<='Z' ; i++) if(cnt[i]==Max) cout << i;
		for(char i='a' ; i<='z' ; i++) if(cnt[i]==Max) cout << i;
		cout << " " << Max << endl;
	}
}
