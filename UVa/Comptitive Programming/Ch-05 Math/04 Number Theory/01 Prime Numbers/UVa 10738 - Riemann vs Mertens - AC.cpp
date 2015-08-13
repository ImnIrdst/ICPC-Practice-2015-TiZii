#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define MAX (1000000+1)
#define INF (int64)1e12
#define int64 long long

using namespace std;

bitset<2000+10> isp;// isprime
int primes[2000+10], ptop=0;
int64 bound;
int mn[MAX],M[MAX];

void genprime(){
    isp.set(); isp[0]=isp[1]=0; bound++;
    for(int i=2 ; i<=2000+10 ; i++){
        if(isp[i]){
            for(int j=i*i ; j<=2000+10 ; j+=i) isp[j]=0;
            primes[ptop++]=i;
            //printf("%d: %d\n", ptop, primes[ptop-1]);
        }
    }
}

//bool isprime(int n){
//    if(n<=bound) return isp[n];
//    for(int i=0 ; i<ptop ; i++){
//        if(n%primes[i]==0) return 0;
//    }
//    return 1;
//}

void sqrfree(int n){
    for(int i=n+n ; i<MAX ; i+=n) mn[i]=0;
}

void nosqr(int n, int d){
    for(int i=d ; i<ptop && n*primes[i]<MAX ; i++){
        mn[n*primes[i]]=-1*mn[n];
    }
}

void solve(int n){
    int tempn=n, cnt=0, i;
    for(i=0 ; i<ptop && primes[i]<=n; i++){
        if(n%primes[i]==0){
            n/=primes[i]; cnt++;
        }
        if(n%primes[i]==0){
            mn[tempn]=0; sqrfree(tempn); return;
        }
    }
    if(n!=1) cnt++;
    if(cnt%2==1) mn[tempn]=-1;
    if(cnt%2==0) mn[tempn]= 1;
    nosqr(tempn,i);
}

void calcM(){
    for(int i=0 ; i<MAX ; i++) mn[i]=-2;
    mn[1]=M[1]=1;
    for(int i=2 ; i<MAX ; i++){
        if(mn[i]==-2) solve(i);
         M[i]=M[i-1]+mn[i];
        //if(i%10000==0) cout << i << endl;
    }
}

int main(){
    bound=200+5; genprime(); calcM(); int n;

    while(cin >> n){
        printf("%8d%8d%8d\n",n,mn[n],M[n]);
    }
}

