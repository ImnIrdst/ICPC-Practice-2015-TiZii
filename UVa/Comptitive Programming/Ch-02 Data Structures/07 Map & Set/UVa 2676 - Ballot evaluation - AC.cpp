#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <sstream>
#define eps (double)1e-9
#define int64 long long

using namespace std;

string out[2]={"incorrect.", "correct."};

int main(){
	int p, g;
	while(cin >> p >> g){
		char name[30]; string str,str2; int integ, frac; map<string, double> mp;
		for(int i=0 ; i<p ; i++){
			scanf("%s %d.%d", &name, &integ, &frac); 
			str=name; mp[str]=integ*10+frac;
		}
		stringstream sstr; int n; cin.ignore();
		for(int i=0 ; i<g ; i++){
			getline(cin,str); sstr << str; double ans=0;
			while(sstr >> str >> str2 && str2=="+"){
				ans+=mp[str];
			}
			ans+=mp[str]; sstr >> n; n*=10;
			cout << "Guess #" << i+1 << " was ";
			if(str2=="=") cout << out[ans==n] << endl;
			if(str2==">") cout << out[ans>n] << endl;
			if(str2=="<") cout << out[ans<n] << endl;
			if(str2==">=") cout << out[ans>=n] << endl;
			if(str2=="<=") cout << out[ans<=n] << endl;
			sstr.clear();
		}
	}
	return 0;
}