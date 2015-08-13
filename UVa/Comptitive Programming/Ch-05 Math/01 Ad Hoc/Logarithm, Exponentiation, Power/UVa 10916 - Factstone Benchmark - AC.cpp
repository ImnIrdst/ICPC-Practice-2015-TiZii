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
	int n;
	while(cin >> n && n){
		double b=pow(2,(n/10-194)); //cout << (int)b << endl;
		double logfact=0;
		for(int ans=1 ; true ; ans++){
			//if(ans%1000==0) cout << ans << endl; 
			logfact+=log2(ans);
			if(logfact>b){
				cout << ans-1 << endl; break;
			}
		}
	}
}
