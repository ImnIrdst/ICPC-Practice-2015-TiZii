#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <sstream>
#define int64 unsigned long long
#define log2(n) log(n)/double(log(2))

using namespace std;

int main(){
	int64 n;
	while(cin >> n){
		int64 len=(int64)(log10(n)+1); double low,high;
		for(int64 i=len+1 ; true ; i++){
			low=i*log2(10)+log2(n);
			high=i*log2(10)+log2(n+1);
			if(ceil(low)<=floor(high)){
				cout << (int64)(ceil(low)) << endl; break;
			}
			else if(i==10000000){
				cout << "no power of 2" << endl;
			}
		}
	}
}
