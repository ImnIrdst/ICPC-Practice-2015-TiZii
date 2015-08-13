#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <fstream>
//#define cin fin
//#define cout fout
#define INF (int)1e9
#define int64 long long

using namespace std;

int m,n,tmp; double tmpval, dpay, mpay,tot, carval,dpre[110];

int main(){
	//ifstream fin("loan.in");
	//ofstream fout("loan.out");
	while(cin >> m >> dpay >> tot >> n && m>=0){
		carval=tot+dpay; mpay=tot/m;
		for(int i=0 ; i<n ; i++){
			cin >> tmp >> tmpval;
			for(int j=tmp ; j<110 ; j++){
				dpre[j]=tmpval;
			}
		}
		carval=carval-(carval*dpre[0]);
		for(int i=0 ; 1 ; i++){
			if(tot<=carval){
				cout << i << (i==1 ? " month" : " months" ) << endl; break;}
			tot-=mpay; carval=carval-(carval*dpre[i+1]);
		}
	}

	return 0;
}