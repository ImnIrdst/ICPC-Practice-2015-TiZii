#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;
const int64 MAX = 1e6 + 100;

bitset<MAX> isp;// isprime
vector<int64> primes;

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
				isp[j]=0;
        }
    }
}

int main(){
    int64 n; genprime();
    while(cin >> n){ 
        int64 tmp=n, cnt=0, cop=n, div=1;//cop = coprimes, div = divisors
        for(int i=0 ; primes[i]*primes[i]<=n; i++){
			int pow=0;
            while(tmp%primes[i]==0){
                tmp/=primes[i]; pow++;
            }
			if(pow) {
				cop -= cop/primes[i]; div *= (pow+1);
			}
        }
        if(tmp>1) cop -= cop/tmp, div *= (1+1);
		cout << n - cop - div + 1 << endl;
    }
}

