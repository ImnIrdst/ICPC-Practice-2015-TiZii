#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define MAX (100000+100)
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

#define MAX2 (10000+10)

int main(){

    bound=100000; genprime();
    int64 a, b, tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int a[MAX2], sum[MAX2]={0}, s=0;
        for(int i=0 ; i<n ; i++){
        	cin >> a[i]; sum[i]=s+a[i]; s=sum[i];
        }
        int maxi=0, maxj=0;
        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<i-1 ; j++){
        		if(isprime(sum[i]-sum[j]+a[j]) && (i-j+1)>(maxi-maxj+1)){
        			maxi=i; maxj=j;
        		}
        	}	
        }
        if(maxi==maxj){ printf("This sequence is anti-primed.\n"); break; }
        printf("Shortest primed subsequence is length %d:",(maxi-maxj+1));
        for(int i=maxj ; i<=maxi ; i++){
        	printf(" %d", a[i]);
        }
        printf("\n");
    }
}

