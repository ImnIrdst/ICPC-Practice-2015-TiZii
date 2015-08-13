#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define int8 long long
//#define cin fin
#define INF (int)1e9

using namespace std;

int8 a[31];

int8 catalan(int8 n){
	if(n==1) return 1;
	int8 m=n-1;
	return (catalan(m)*(2*m+2)*(2*m+1))/((m+1)*(m+2));
}

int main(){
	//ifstream fin("in.txt");
	int8 n,m,t=0;
	for(int i=1 ; i<31 ; i++){
		a[i]=catalan(i);
	}
	while(cin >> n){
		if(t++!=0) cout << endl;
		cout << a[n] << endl;
	}
	return 0;
}