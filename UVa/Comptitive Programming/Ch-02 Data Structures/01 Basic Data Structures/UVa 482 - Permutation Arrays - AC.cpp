#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
//#define cin fin
#define MAX (int)1e6

using namespace std;

int a[MAX]; string b[MAX];

int main(){
	//ifstream fin("in.txt");
	long long tc; cin >> tc; bool first=true;
	string str; getline(cin,str); 
	while (tc--){
		getline(cin,str); getline(cin,str); 
		stringstream sstr; sstr << str; int i=0;
		while(sstr >> a[i++]); 
		getline(cin,str); sstr.clear(); sstr << str;
		string tmp; i=0;
		while(sstr >> tmp){
 			b[a[i++]-1]=tmp;
		}
		int n=i;
		if(!first) cout << endl; first=false;
		for(int i=0; i<n ; i++){
			cout << b[i] << endl;
		}
	}
}