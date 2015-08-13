#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-4;

typedef long long int64;

int val(char c){
	return (c>='0' && c<='9' ? c-'0' : c-'A'+10);
}

int64 toBase10(string& num, int& base){
	int64 ret=0;
	for(int i=0 ; i<num.length() ; i++){
		ret = ret*base + val(num[i]);
	}
	return ret;
}

int main(){
	string st1, st2;
	while(cin >> st1 >> st2){
		int ii=2, jj=2;

		for(int i=0 ; i<st1.size() ; i++) ii = max(ii, val(st1[i])+1);
		for(int j=0 ; j<st2.size() ; j++) jj = max(jj, val(st2[j])+1);

		bool found=0;
		for(int i=ii ; i<=36 && !found ; i++){
			for(int j=jj ; j<=36 && !found ; j++){
				if(toBase10(st1,i) == toBase10(st2,j)){
					printf("%s (base %d) = %s (base %d)\n", st1.c_str(), i, st2.c_str(), j); 
					found=1;
				}
			}
		}
		if(!found) printf("%s is not equal to %s in any base 2..36\n", st1.c_str(), st2.c_str()); 
	}
}