#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long

using namespace std;

int primes[25],nep[25],np=25,lastprime;//nep = number of each prime, np = Total number of prime numbers

int main(){
	int idx=0;
	for(int i=2 ; i<100 ; i++){
		bool flag=1;
		for(int j=2 ; j*j<=i && flag ; j++){
			if(i%j==0){
				flag=0;
			}
		}
		if(flag) primes[idx++]=i;
	}
	int n;
	while(cin >> n && n){
		for(int i=0 ; i<np ; i++) nep[i]=0;
		lastprime=0;
		for(int i=2 ,j=0; i<=n ; i++){
			int tmp=i; j=0;
			while(tmp!=1){
				if(tmp%primes[j]==0){ tmp/=primes[j]; nep[j]++;}
				else j++;
			}
			lastprime=max(lastprime,j);
		}
		printf("%3d! =", n);
		for(int i=0 ; i<=lastprime ; i++){
			if(i>0 && i%15==0 ) printf("\n      ");
			printf("%3d", nep[i]);
		}
		printf("\n");
	}
	return 0;
}