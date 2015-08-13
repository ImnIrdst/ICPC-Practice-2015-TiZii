#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
//#define cin fin
#define INF (long long)1e9

using namespace std;

int main(){
	//ifstream fin("in.txt");
	//long long tc; cin >> tc;
	string str; char s[100000]; int flag=1;
	while(scanf("%[^\n]",s)!=EOF){
		str=s;
		for(int i=str.find("\"") ; i<str.length() && str.substr(i,str.length()).find("\"")!=-1 ; i+=str.substr(i,str.length()).find("\"")){
			if(flag==1) str.replace(i,1,"``");
			else str.replace(i,1,"\'\'");
			flag=1-flag;
			i++;
		}
		cout << str << endl;
		getchar();
	}
}