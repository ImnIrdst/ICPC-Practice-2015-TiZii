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
        int64 LPD=-1, tmp=num, cnt=0;
        for(int i=0 ; primes[i]*primes[i]<=num; i++){
            while(tmp%primes[i]==0){
                tmp/=primes[i]; LPD=primes[i];
            }
            if(LPD==primes[i]) cnt++;
        }
        if(tmp>1 && LPD!=-1) LPD=tmp, cnt++;
        if(cnt==1) LPD=-1;
        cout << LPD << endl;
    }
}

