#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int n,r,t=1;
	while(cin >> n >> r && (r||n)){
		int imposs=1;printf("Case %d: ",t++ );
		for(int i=1 ; i<=27 && imposs ; i++){
			if(r*i>=n) imposs=0, printf("%d\n",i-1 );
		}
		if(imposs) printf("impossible\n");
	}
	
	return 0;
}