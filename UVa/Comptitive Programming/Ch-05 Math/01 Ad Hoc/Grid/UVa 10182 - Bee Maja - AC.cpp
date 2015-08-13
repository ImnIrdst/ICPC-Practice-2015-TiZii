#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		int ans=1, flag=1, x, y, i, t;
		for(i=1 ; ans<n ; i++) ans+=i*6; i--;
		if(n==1) x=0,y=0; else x=i, y=0;
		t=i; while(t-- && ans!=n) y--, ans--; 
		t=i; while(t-- && ans!=n) x--, ans--;
		t=i; while(t-- && ans!=n) x--, y++, ans--;
		t=i; while(t-- && ans!=n) y++, ans--;
		t=i; while(t-- && ans!=n) x++, ans--;
		t=i; while(t-- && ans!=n) y--, x++, ans--;
		printf("%d %d\n",x,y);
	}
	return 0;
}