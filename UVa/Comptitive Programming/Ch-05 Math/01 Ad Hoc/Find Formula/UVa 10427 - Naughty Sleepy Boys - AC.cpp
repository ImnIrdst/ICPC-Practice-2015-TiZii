#include <iostream>
#include <stdio.h>
#include <cmath>
#define int64 unsigned long long

using namespace std;

int64 po10[11], nod[11],n;// po10[i] = i^10 (power of 10), nod[i]==max number of digits with i digits 

int main(){
	nod[0]=0;
	for(int64 i=1, p=1; i<=10 ; i++, p*=10){
		po10[i]=p; nod[i]=nod[i-1]+i*9*p;
	}
	while(cin >>n && n){
		int64 i,j,m;
		for(i=1 ; i<=10 && n>nod[i] ; i++);
		j=n-nod[i-1]; m=(po10[i]-1)+(i-1+j)/i;
		if(j%i) for(int k=i-(j%i); k ; k--) m/=10;
		cout << m%10 << endl;
	}
	return 0;
}