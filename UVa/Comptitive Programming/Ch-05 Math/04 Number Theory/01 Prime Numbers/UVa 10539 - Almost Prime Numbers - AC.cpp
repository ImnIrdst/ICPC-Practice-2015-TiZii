#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define MAX (1000000+100)
#define INF (int64)1e12
#define int64 long long

using namespace std;

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

bool isprime(int n){
    if(n<=bound) return isp[n];
    for(int i=0 ; i<primes.size() ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}

int main(){
    bound=1000000; genprime();
    int64 a, b, tc; cin >> tc;
    while(tc--){
        cin >> a >> b; int64 cnt=0, i;
        for(i=0 ; primes[i]<=b && i<primes.size() ; i++){
            for(int64 j=primes[i]*primes[i] ; j<INF && j<=b ; j*=primes[i]){
                if(j>=a) cnt++;//, cout << j << endl;
            }
        }
        cout << cnt << endl;
    }
}

