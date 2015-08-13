#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define MAX (1000000+10)

using namespace std;

int b[MAX];

int main(){
	string str;
	while(cin >> str && str!="."){
		string str2=str,str3=str; 
		reverse(str2.begin(),str2.end()); 
		str=str2+'$'+str; int j=b[0]=-1;
		for(int i=0 ; i<str.length() ; i++){
			while(j>=0 && str[i]!=str[j]) j=b[j];
			b[i+1]=++j; //cout << b[i] << " ";
		}
		int psize=min((int)str2.length(),b[str.length()]);
		//cout << psize << " " << str << endl;
		for(int i=psize ; i<str2.size() ; i++){
			str3+=str2[i];
		}
		cout << str3 << endl;
	}
}
