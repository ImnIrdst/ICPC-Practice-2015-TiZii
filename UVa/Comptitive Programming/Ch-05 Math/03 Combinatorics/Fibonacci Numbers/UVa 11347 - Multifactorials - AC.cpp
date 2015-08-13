#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#include <map>
#define MAX (1000+10)

using namespace std;

typedef long long int int64;

bitset<MAX> isp;// isprime
vector<int64> primes;
int64 bound;

void genprime(){
    isp.set(); isp[0]=isp[1]=0; bound++;
    for(int64 i=2 ; i<=bound ; i++){
        if(isp[i]){
            for(int64 j=i ; j<=bound ; j+=i)
                isp[j]=0;
            primes.push_back(i);
        }
    }
}


int main(){
    int64 num,t=1,tc; bound=1000+5; genprime(); cin >> tc;
    while(tc--){
        scanf("%lld",&num); int cnt=0; char c;
        while((c=getchar()) && c!='\n')
            cnt++;
        map<int,int> factPow;
        for(int n=num ; n>1 ; n-=cnt){
            int tmp=n, i=0;
            while(tmp>1){
                int Pow=0;
                while(tmp%primes[i]==0){
                    tmp/=primes[i]; Pow++;
                }
                if(Pow!=0) factPow[(int)primes[i]]+=Pow;
                i++;
            }
        }
        int64 ans=1; map<int,int>::iterator itr;
        for(itr=factPow.begin() ; itr!=factPow.end() ; itr++){
            ans*=itr->second+1;
            if(ans>(int64)1e18) break;
        }
        printf("Case %lld: ", t++);
        if(ans>(int64)1e18) printf("Infinity\n");
        else printf("%lld\n", ans);
    }
}

