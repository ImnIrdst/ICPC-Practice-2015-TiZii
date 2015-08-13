#include <iostream>
#include <string>

using namespace std;

typedef long long int64;

int bigmod(string& year, int m){
	int mod=0;
	for(int i=0 ; i<year.length() ; i++){
		mod = (mod*10+(year[i]-'0')) % m;
	}
	return mod;
}

int main(){
	string year; int first=1;
	while(cin >> year){
		int ordinary=true;
		if(!first) cout << endl; first=0; bool isleap=false;
		if((bigmod(year,4)==0 && bigmod(year,100)!=0) || (bigmod(year,400)==0))
			cout << "This is leap year." << endl, isleap=true, ordinary=false;
		if((bigmod(year,15)==0))
			cout << "This is huluculu festival year." << endl, ordinary=false;
		if((bigmod(year,55)==0) && isleap)
			cout << "This is bulukulu festival year." << endl, ordinary=false;
		if((ordinary))
			cout << "This is an ordinary year." << endl;
	}
}