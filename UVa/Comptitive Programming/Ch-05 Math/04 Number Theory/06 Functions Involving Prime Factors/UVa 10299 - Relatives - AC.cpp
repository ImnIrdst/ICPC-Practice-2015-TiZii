#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#define MAX (11000000+10)

using namespace std;

typedef long long int int64;

bitset<MAX> isp;// isprime
vector<int64> primes;
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


int main(){
    int64 num; bound=11000000; genprime();
    while(cin >> num && num){
        num=abs(num);
        int64 tmp=num; vector<int64> fact;
        for(int i=0 ; primes[i]*primes[i]<=num; i++){
            int Pow=0;
            while(tmp%primes[i]==0){
                tmp/=primes[i]; Pow++;
            }
            if(Pow) fact.push_back(primes[i]);
        }
        if(tmp>1) fact.push_back(tmp);
        int64 rel=num;
        for(int i=0 ; i<fact.size() ; i++){
            rel-=rel/fact[i];
        }
        if(num==1) rel=0;
        cout << rel << endl;
    }
}

