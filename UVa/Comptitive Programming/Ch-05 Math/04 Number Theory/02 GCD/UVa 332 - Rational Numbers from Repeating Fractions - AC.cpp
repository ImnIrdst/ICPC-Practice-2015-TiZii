#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long int64;

double StoD(string str){
	if(str.length()==0) return 0;
	stringstream sstr(str);
	double x; sstr >> x;
	return x;
}

int64 gcd(int64 a, int64 b){
	return (b ? gcd(b,a%b) : a);
}

int main(){
	string str; int64 j, cs=1;
	while(cin >> j && j!=-1 ){ cin >> str;
		double org = StoD(str)+1e-10; 
		int64 k = str.length()-2-j;
		int64 a = StoD(str.substr(2,k+j))+1e-10;
		int64 b = StoD(str.substr(2,  k))+1e-10;
		int64 numer = a-b;
		int64 denom = pow(10.0,k+j)-pow(10.0,k)+1e-10;
		if(j==0) numer=org*pow(10.0, k+j)+1e-10, denom = pow(10.0,k)+1e-10;
		if(org==1) numer = 1, denom=1;
		int64 gc = gcd(numer,denom);
		numer/=gc; denom/=gc;
		cout << "Case " << cs++ << ": " ;
		cout << numer << "/" << denom << endl;
	}
}