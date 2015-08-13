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

double Dabs(double a){ return ( a>0 ? a : -1*a);}

int main(){
	int p, g;
	while(cin >> p >> g){
		string str,str2; double tmp; map<string, double> mp;
		for(int i=0 ; i<p ; i++){
			cin >> str >> tmp; mp[str]=tmp;
		}
		stringstream sstr; double n; cin.ignore();
		for(int i=0 ; i<g ; i++){
			getline(cin,str); sstr << str; double ans=0;
			while(sstr >> str >> str2 && str2=="+"){
				ans+=mp[str];
			}
			ans+=mp[str]; sstr >> n;
			cout << "Guess #" << i+1 << " was ";
			if(str2=="=") cout << out[Dabs(ans-n)<eps] << endl;
			if(str2==">") cout << out[ans>n] << endl;
			if(str2=="<") cout << out[ans<n] << endl;
			if(str2==">=") cout << out[(Dabs(ans-n)<eps || ans>n)] << endl;
			if(str2=="<=") cout << out[(Dabs(ans-n)<eps || ans<n)] << endl;
			sstr.clear();
		}

	}
	return 0;
}