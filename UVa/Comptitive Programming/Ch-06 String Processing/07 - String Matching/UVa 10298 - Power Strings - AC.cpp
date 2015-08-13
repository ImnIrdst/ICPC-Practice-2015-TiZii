#include <iostream>
#include <cstdio>
#include <string>
#define MAX (1000000+10)

using namespace std;

int b[MAX];

int main(){
	string str;
	while(cin >> str && str!="."){
		int j=b[0]=-1, len=str.length();
		for(int i=0 ; i<len ; i++){
			while(j>=0 && str[i]!=str[j]) j=b[j];
			b[i+1]=++j; //cout << b[i] << " ";
		}
		//cout << b[len] << endl;
		cout << len/(len-b[len]) << endl;
	}
}
