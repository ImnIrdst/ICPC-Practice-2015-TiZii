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
    swap(primes[1],primes[2]);
}

int main(){
    int64 n; bound=1000000; genprime();
    while(cin >> n && n){
        int64 p2=0,p5=0,ans=1;
        for(int i=2 ; i<=n ; i*=2) p2++;
        for(int i=5 ; i<=n ; i*=5) p5++;
        for(int i=0 ; i<p2-p5 ; i++) ans=(ans*2)%10;
        for(int i=2 ; i<primes.size() && primes[i]<=n; i++){
            for(int64 j=primes[i] ; j<=n ; j*=primes[i]){
                ans=(ans*primes[i])%10;
            }
        }
        cout << ans << endl;
    }
}

