#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		int ans=1, flag=1, x, y, i;
		for(i=1 ; ans<n ; i++){
			ans+=i+1; flag=1-flag;
		}
		if( flag) x=1, y=i; if(!flag) x=i, y=1;
		if( flag) while(ans!=n) ans--, x++, y--;
		if(!flag) while(ans!=n) ans--, x--, y++;
		printf("TERM %d IS %d/%d\n",n,x,y);
	}
	return 0;
}