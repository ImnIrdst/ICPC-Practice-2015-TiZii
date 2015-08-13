#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define MAX (1000000+100)
#define int64 long long

using namespace std;

bitset<MAX> isp;// isprime
vector<int> primes;
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
    bound=1000000; genprime(); int n;
    //cout << "s" << endl;
    while(cin >> n && n){
        int a,b; bool found=false;
        for(int i=0 ; i<primes.size() && primes[i]<n && !found ; i++){
            for(int j=i ; j<primes.size() && primes[i]+primes[j]<=n && !found ; j++){
               if(primes[i]+primes[j]==n) a=primes[i], b=primes[j], found=1;
            }
        }
        if(found==0) printf("Goldbach's conjecture is wrong.\n");
        if(found==1) printf("%d = %d + %d\n",n , a, b);
    }
}

