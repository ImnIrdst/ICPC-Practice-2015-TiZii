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

bool isprime(int n){
    if(n<MAX) return isp[n];
	for(int i=0 ; i<primes.size() ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}

int main(){
	int n; genprime();
	while(cin >> n && n){
		int ans=0;
		for(int i=0 ; primes[i]<=n/2 && i<primes.size(); i++){
			if(isprime(n-primes[i])) ans++;
		}
		cout << ans << endl;
	}
}