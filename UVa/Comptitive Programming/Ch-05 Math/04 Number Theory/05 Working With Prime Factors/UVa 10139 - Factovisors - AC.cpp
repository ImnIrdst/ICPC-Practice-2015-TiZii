#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#define MAX (11000000+10)

using namespace std;

typedef unsigned long long int int64;

bitset<MAX> isp;// isprime
vector<int64> primes,fact,pof;//pof=PowerOfFactors
int64 bound;

void genprime(){
    isp.set(); isp[0]=isp[1]=0; bound++;
    for(int64 i=2 ; i<=bound ; i++){
        if(isp[i]){
            for(int64 j=i*i ; j<=bound ; j+=i) isp[j]=0;
            primes.push_back(i);
            //printf("%d: %d\n", primes.size(), primes.back());
        }
    }
}

int64 getpower(int64 n, int64 f){
    int64 val=0;
    for(int64 p=f ; p<=n ; p*=f){
        val+=n/p;
    }
    return val;
}

bool check(int64 n, int64 m){
    if(n>=m) return 1;
    if(m==0) return 0;
    for(int i=0 ; i<fact.size() ; i++){
        //printf("%lld %lld %lld\n",n ,fact[i], getpower(n,fact[i]));
        if(getpower(n,fact[i])<pof[i]){
            return 0;
        }
    }
    return 1;
}


int main(){
    int64 n,m; bound=1000000; genprime();
    while(cin >> n >>m){
        int64 tmp=m; fact.clear(); pof.clear();
        for(int i=0 ; primes[i]*primes[i]<=m; i++){
            int64 powi=0;
            while(tmp%primes[i]==0){
                tmp/=primes[i]; powi++;
            }
            if(powi>0){
                fact.push_back(primes[i]), pof.push_back(powi);
                //printf("%lld %lld\n",fact.back(),pof.back());
            }

        }
        if(tmp>1) fact.push_back(tmp), pof.push_back(1);
        bool ans=check(n,m);
        if( ans) printf("%lld divides %lld!\n", m, n);
        if(!ans) printf("%lld does not divide %lld!\n", m, n);
    }
}

