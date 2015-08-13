#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long int64;
const int64 MAX = 1e6 + 10;

bitset<MAX> isp;// isprime
vector<int64> primes, divs, RMQ, RMQval; //pfs = prime factors, pws = prime powers

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){ primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }
}

int numOfDivisors(int n){
	int64 tmp=n, div=1;
    for(int i=0, pf=2 ; pf*pf<=n; i++, pf=primes[i]){
        int pow=0;
        while(tmp%pf==0){
            tmp/=pf; pow++;
        }
        if(pow) div *= (pow+1);
    }
	if(tmp>1) div *= (1+1);
	return div;
}

void initialize(){
	divs.resize(MAX);
	RMQ.assign(MAX,0);
	RMQval.assign(MAX,0);
	for(int i=1 ; i<MAX ; i++){
		divs[i]=numOfDivisors(i);
		if(RMQval[i-1]<=divs[i]) RMQval[i]=divs[i], RMQ[i]=i;
		else RMQval[i]=RMQval[i-1], RMQ[i]=RMQ[i-1]; 
	}
}

int main(){
    int n;
	int tc;
	cin >> tc;
	genprime();
	initialize();
    while(tc--){cin >> n;                    
        cout << RMQ[n] << endl;
    }
}

