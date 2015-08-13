#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	int n;
	while(cin >> n && n!=-1){
		int imposs=1, ans=-1;
		for(int k=sqrt(n)+1 ; k>1 && imposs ; k--){
			int tmp=n,i;
			for(i=0 ; i<k && tmp%k==1 ; i++){
				tmp-=tmp/k+1;
			}
			if( i==k && tmp%k==0) ans=k, imposs=0;
			//if(tmp==0) imposs=1;
		}
		//printf("%d people and 1 monkey\n", ans);// break;
		if( imposs) printf("%d coconuts, no solution\n",n);
		if(!imposs) printf("%d coconuts, %d people and 1 monkey\n",n, ans);
	}
}