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
    for(int i=0 ; i<primes.size() && primes[i]*primes[i]<=n ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}
//generation prime factors of a number
int main(){
    int64 n; genprime();
    while(cin >> n && n){
		int ans=0, tmp=n;
        for(int i=0, pf=2 ; pf*pf<=n; i++, pf=primes[i]){
            if(tmp%pf==0) ans++;
            while(tmp%pf==0) tmp/=pf;
        }
        if(tmp>1) ans++;
        cout << n << " : " << ans << endl;
    }
}

