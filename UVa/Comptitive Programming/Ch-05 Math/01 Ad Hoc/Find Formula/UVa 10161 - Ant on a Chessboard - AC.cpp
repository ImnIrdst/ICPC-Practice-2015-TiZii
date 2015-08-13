#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	int n;
	while(cin >>n && n){
		int ans=1, flag=0,i,j;
		for(i=1,j=1 ; ans<n  ;  j++){
			i+=2; ans+=i; flag=1-flag;
		}
		ans-=i/2; int x=j, y=j;
		if(ans==n);
		else if( flag && ans>n) for(x ; ans!=n ; x--) ans--;
		else if( flag && ans<n) for(y ; ans!=n ; y--) ans++;
		else if(!flag && ans<n) for(x ; ans!=n ; x--) ans++;
		else if(!flag && ans>n) for(y ; ans!=n ; y--) ans--;
		printf("%d %d\n", x, y );
	}
	return 0;
}