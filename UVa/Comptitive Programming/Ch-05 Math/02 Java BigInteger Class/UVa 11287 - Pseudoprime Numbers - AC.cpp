#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;

const int64 MAX = 1e6 + 100;

bitset<MAX> isp;// isprime
vector<int64> primes, pfs, pws; //pfs = prime factors, pws = prime powers

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){ primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }
}

bool isprime(int n){
    if(n<MAX) return isp[n];
    for(int i=0 ; i<primes.size() ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}

int64 Square(int64 x){ return x*x; }

int64 PowMod(int64 b, int64 p, int64 m){
	if(p   ==  0) return 1;
	if(p%2 ==  0) return Square(PowMod(b,p/2,m))%m;
	if(p%2 !=  0) return (((b%m)*PowMod(b,p-1,m))%m)%m;
}

int main(){
	int p, a; genprime();
	while(cin >> p >> a && (p||a)){
		int pw = PowMod(a, p, p); 
		if( isprime(p) ) a=-1;
		if( pw == a ) cout << "yes" << endl;
		if( pw != a ) cout << "no" << endl;
	}
}