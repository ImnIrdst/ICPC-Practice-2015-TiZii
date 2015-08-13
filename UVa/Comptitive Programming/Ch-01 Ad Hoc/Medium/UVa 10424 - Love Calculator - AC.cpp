#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

int sumofdigs(int n){
	stringstream sstr; sstr << n;
	string str; sstr >> str;
	
	int ret = 0;
	for(int i=0; i<str.length() ; i++){
		ret += (str[i]-'0');
	}
	return ret;
}

int main(){
	string s1, s2;
	while(getline(cin,s1) && getline(cin,s2)){
		int i1=0, i2=0;
		for(int i=0 ; i<s1.length() ; i++) {
			if(isalpha(s1[i]))
				i1 += (isupper(s1[i]) ? s1[i]-'A'+1 : s1[i]-'a'+1); 
		}
		while(i1/10!=0) i1 = sumofdigs(i1);
		
		for(int i=0 ; i<s2.length() ; i++) {
			if(isalpha(s2[i]))
				i2 += (isupper(s2[i]) ? s2[i]-'A'+1 : s2[i]-'a'+1); 
		}
		while(i2/10!=0) i2 = sumofdigs(i2);
		double n1=max(i1,i2), n2=min(i1,i2);

		printf("%.2lf %c\n", (n2/n1)*100, '%');
	}
}
