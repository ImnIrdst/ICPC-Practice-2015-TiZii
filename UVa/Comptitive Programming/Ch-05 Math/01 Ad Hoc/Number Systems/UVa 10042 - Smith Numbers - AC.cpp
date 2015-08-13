#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#define MAX (5842+10)

using namespace std;

vector<int> primes;

void genprimes(int n){
	for(int num=2; num<=n ; num++){
		int sq=(int)(sqrt(num)+1), isprime=1; 
		for(int i=0 ; i<primes.size() && primes[i]<sq ; i++){
			if(num%primes[i]==0){
				isprime=0; break;
			}
		}
		if(isprime) primes.push_back(num);
	}
}

bool isPrime(int num){
	int sq=(int)(sqrt(num)+1), isprime=1; 
	for(int i=0 ; i<primes.size() && primes[i]<sq ; i++){
		if(num%primes[i]==0){
			isprime=0; break;
		}
	}
	if(isprime) primes.push_back(num);
	return isprime;
}

int sumofdigits(int n){
	int sum=0;
	for(int k=n ; k>0 ; k/=10) sum+=k%10;
	return sum;
}

int main(){
	int tc=0; cin >> tc; genprimes(10000);
	while(tc--){
		int n; cin >> n; bool found=0; int ans, num=n;
		while(!found){
			num++;
			if(!isPrime(num)){
				int sum=0, tmp=num;
				for(int i=0; i<primes.size() ; i++){
					if(primes[i]>int(sqrt(tmp)+1)) break;
					while(tmp%primes[i]==0){
						sum+=sumofdigits(primes[i]); tmp/=primes[i];
					}
				}
				if(tmp>1) sum+=sumofdigits(tmp);
				if(sumofdigits(num)==sum) found=1, ans=num;
			}
		}
		cout << ans << endl;
	}
}
